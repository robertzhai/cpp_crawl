//
//  main.cpp
//  CrawlIpCn
//
//

#include <iostream>
#include <exception>
#include <cstdio>
#include "httpclient.hpp"

#include "JsonUtil.h"


using namespace std;


int main(int argc, const char **argv) {

	std::string url =
			"https://www.apiopen.top/weatherApi?city=%E5%8C%97%E4%BA%AC",
			apiRes = "";
	HttpClient client;
	apiRes = client.get(url);
	std::cout << "apiRes:" << apiRes << std::endl;

	Json::Value value;
	JsonUtil jsonutil;
	bool parseResult = jsonutil.praseJson(apiRes, value);

	if (false == parseResult) {
		cerr << endl << "read value error \n";
		return -1;
	} else {
		cout << "json util:"<< value["code"].asString() << endl;
		cout << value["msg"].asString() << endl;
	}

	std::cout << "start with cmake and utils ";

	return 0;
}
