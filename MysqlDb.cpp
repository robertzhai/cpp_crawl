/*
 * MysqlDb.cpp  
 * Author: robertzhai
 */

#include "MysqlDb.h"
#include "TimeUtil.h"
#include "IpCn.h"

namespace Robert {

MysqlDb::MysqlDb() :
		conn(false) {

	if (conn.connect("crawl", "localhost", "root", "")) {
		// Retrieve a subset of the sample stock table set up by resetdb
		// and display it.
	} else {
		std::cerr << "DB connection failed: " << conn.error() << std::endl;
	}
}

MysqlDb::~MysqlDb() {

}

void MysqlDb::debug() {

	mysqlpp::Query query = conn.query("select ip from ip_cn");
	if (mysqlpp::StoreQueryResult res = query.store()) {
		std::cout << "We have:" << std::endl;
		mysqlpp::StoreQueryResult::const_iterator it;
		for (it = res.begin(); it != res.end(); ++it) {
			mysqlpp::Row row = *it;
			std::cout << '\t' << row[0] << std::endl;
		}
	} else {
		std::cerr << "Failed to get item list: " << query.error() << std::endl;
	}

}

bool MysqlDb::addIp(std::string &ip) {

	try {
		mysqlpp::Query query = conn.query(
				"select ip from ip_cn where ip='" + ip + "'");
		if (mysqlpp::StoreQueryResult res = query.store()) {
			// Show how many rows are in result, if any
			mysqlpp::StoreQueryResult::size_type num_results = res.size();
			if (num_results > 0) {
				std::cout << "ip: " + ip + " already existed \n " << std::endl;
				return true;
			} else {
				std::string time = std::to_string(Robert::TimeUtil::getCurTimestamp());
				std::string sql = "insert ignore into  ip_cn set ip='" + ip
						+ "',create_time=" + time + ",update_time=" + time;
				return query.exec(sql);
			}
		} else {
			std::cerr << "Failed to get item list: " << query.error() << std::endl;
		}
	} catch (const mysqlpp::BadQuery& er) {
		// Handle any query errors
		std::cout << "QUERY ERROR: " << er.what() << " \n ";
	} catch (const mysqlpp::Exception& er) {
		// Catch-all for any other MySQL++ exceptions
		std::cout << "GENERAL ERROR: " << er.what() << "\n ";
	}
	return false;

}

} /* namespace Robert */
