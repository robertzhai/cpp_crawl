/*
 * StrUtil.cpp  
 * Author: robertzhai
 */

#include "StrUtil.h"

bool StrUtil::isHttps(std::string &url) {

	return url.substr(0, 5) == "https";
}
