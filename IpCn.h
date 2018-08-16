/*
 * IpCn.h  
 * Author: robertzhai
 */

#ifndef IPCN_H_
#define IPCN_H_

#include <iostream>

class IpCn {

public:
	IpCn() {
	}
	~IpCn() {
	}

	void fetchStart();
	std::vector<std::string> parseHtml(std::string &str);

	void parseIp(std::string &str, std::vector<std::string> & ips);

};

/*
sql_create_4("IpCnModel",1,4,
		mysqlpp::sql_int_unsigned,id,
		mysqlpp::sql_char ip,
		mysqlpp::sql_int, create_time,
		mysqlpp::sql_int, update_time)

*/
#endif /* IPCN_H_ */
