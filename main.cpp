//
//  main.cpp
//  CrawlIpCn
//
//

#include <iostream>
#include <exception>
#include <cstdio>

#include "IpCn.h"

using namespace std;

int main(int argc, const char **argv) {

	std::cout << "main start \n";

	try {
		IpCn ipcn;
		ipcn.fetchStart();

	} catch (exception &e) {
		std::cout << "in main catch exception " << e.what() << std::endl;
	}

	std::cout << "main ended \n";

	return 0;
}
