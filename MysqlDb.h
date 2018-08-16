/*
 * MysqlDb.h  
 * Author: robertzhai
 */

#include <mysql++.h>
#include <iostream>
#include <iomanip>

#ifndef MYSQLDB_H_
#define MYSQLDB_H_

namespace Robert {

class MysqlDb {
public:
	MysqlDb();
	virtual ~MysqlDb();
	void debug();

	bool addIp(std::string &ip);

private:
	mysqlpp::Connection conn;

};

} /* namespace Robert */

#endif /* MYSQLDB_H_ */

