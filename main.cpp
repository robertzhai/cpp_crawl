//
//  main.cpp
//  CrawlIpCn
//
//

#include <iostream>
#include <exception>
#include <cstdio>

#include "IpCn.h"
#include "Logger.h"

using namespace std;

int main(int argc, const char **argv) {

	Robert::Logger::info("main start \n");
	try {
		IpCn ipcn;
		ipcn.fetchStart();

	} catch (exception &e) {
		Robert::Logger::error("in main catch exception " << e.what());
	}

	Robert::Logger::info("main ended \n");

	return 0;
}
