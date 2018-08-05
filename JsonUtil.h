/*
 * JsonUtil.h
 * Author: robertzhai
 */

#ifndef JSONUTIL_H_
#define JSONUTIL_H_

#include <json/json.h>


class JsonUtil {

public:
	JsonUtil() {

	}
	~JsonUtil() {

	}
	bool praseJson(std::string & json, Json::Value & value);

};

#endif /* JSONUTIL_H_ */
