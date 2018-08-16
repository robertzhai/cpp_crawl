/*
 * TimeUtil.cpp  
 * Author: robertzhai
 */

#include "TimeUtil.h"

namespace Robert {


long TimeUtil::getCurTimestamp() {
		std::time_t time = std::time(0);  // t is an integer type
		return time;
	}

} /* namespace Robert */
