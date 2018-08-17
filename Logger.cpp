/*
 * Logger.cpp  
 * Author: robertzhai
 */

#include "Logger.h"
#include <iostream>
#include <iostream>

namespace Robert {

std::string Logger::LOG_DIR = "/data/logs/";
auto basic_file_log = spdlog::basic_logger_mt("basic_logger",
		Logger::LOG_DIR + "cpp_log.txt");

void Logger::info(std::string msg) {
	std::cout << "msg:" << msg << std::endl;
	basic_file_log->info(msg);
}
void Logger::error(std::string msg) {
	std::cout << "msg:" << msg << std::endl;
	basic_file_log->error(msg);
}

} /* namespace Robert */
