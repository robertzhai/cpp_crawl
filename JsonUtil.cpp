/*
 * JsonUtil.cpp
 *
 * Author: robertzhai
 */

#include "JsonUtil.h"

bool praseJson(std::string & json, Json::Value &value) {

	Json::Reader reader;
	if (false == reader.parse(json, value)) {
		return true ;
	}
	return false;
}

