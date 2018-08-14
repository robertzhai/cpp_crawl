/*
 * IpCn.cpp  
 * Author: robertzhai
 */

#include "IpCn.h"
#include "httpclient.hpp"
#include <exception>
#include <string>
#include <regex>

#include <iostream>
#include <exception>
#include <string>
#include <regex>
#include <vector>

#include<typeinfo>

void IpCn::fetchStart() {

	std::vector<std::string> ips;
	std::string result;
	std::vector<std::string> urlList = {
					"https://raw.githubusercontent.com/ym/chnroutes2/master/chnroutes.txt",
					"http://f.ip.cn/rt/chnroutes.txt",
					"http://f.ip.cn/rt/isproutes-ct.txt",
					"http://f.ip.cn/rt/isproutes-cu.txt",
					"http://f.ip.cn/rt/isproutes-cmcc.txt",
			"http://f.ip.cn/rt/isproutes-edu.txt" };
	try {
		std::vector<std::string> header =
				{
						"accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8",
						"user-agent: Mozilla/5.0 (Linux; Android 5.0; SM-G900P Build/LRX21T) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/67.0.3396.99 Mobile Safari/537.36",
						"Referer: https://ip.cn/" };

		HttpClient client;
		for (auto url : urlList) {
			std::cout << "start to fetch url:" << url << std::endl;
			result = client.get(url, header);
			parseIp(result, ips);
		}

	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

}

std::vector<std::string> IpCn::parseHtml(std::string &str) {
	std::vector<std::string> result;
	std::smatch match;
	std::regex reg("(http|https):\\/\\/.*?");

	std::regex_match(str, match, reg);

	for (int i = 0, len = match.size(); i < len; ++i) {
		std::cout << "match " << i << " (" << match[i] << ")";
		result.push_back(match[i]);
	}
	return result;

}

void IpCn::parseIp(std::string &str, std::vector<std::string> & ips) {

	std::cout << "in parseIp \n str: " << str;
	std::vector<std::string> result;
	std::smatch match;
	const std::regex pattern("\\d{1,3}.\\d{1,3}.\\d{1,3}.\\d{1,3}");

	while (std::regex_search(str, match, pattern)) {
		std::cout << match.str() << std::endl;
		ips.push_back(match.str());
		str = match.suffix().str();
		std::cout << str << std::endl;

	}
	for (auto str : ips) {
		std::cout << "\n ip:" << str << std::endl;
	}
}

