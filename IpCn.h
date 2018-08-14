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
	std::vector<std::string>  parseHtml(std::string &str);

	void parseIp(std::string &str, std::vector<std::string> & ips);

};

#endif /* IPCN_H_ */
