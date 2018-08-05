/*
 * JsonUtil.cpp
 *
 * Author: robertzhai
 */

#include "JsonUtil.h"

bool JsonUtil::praseJson(std::string & json, Json::Value &value) {

	Json::Reader reader;
	if (false == reader.parse(json, value)) {
		return false ;
	}
	return true;
}

