/*
 * Logger.h  
 * Author: robertzhai
 */

#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h" //support for stdout logging
#include "spdlog/sinks/basic_file_sink.h" // support for basic file logging
#include "spdlog/sinks/rotating_file_sink.h" // support for rotating file logging

namespace Robert {

class Logger {

public:
	void static  info(std::string msg);
	void static  error(std::string msg);

	static std::string LOG_DIR ;
};



} /* namespace Robert */


#endif /* LOGGER_H_ */
