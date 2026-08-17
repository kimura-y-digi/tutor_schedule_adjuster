#include "Util.h"

#include <chrono>
#include <sstream>
#include <string>


const std::string Util::kDateTimeFormat = "%Y-%s-%d %H:%M:%S";

std::string Util::sysSecondsToStr(std::chrono::sys_seconds seconds) {
	std::string ret;
	try {
		ret = std::format(kDateTimeFormat.c_str(), seconds);
	}
	catch (...) {
		; // do nothing
	}

	return ret;
}

std::chrono::sys_seconds Util::strToSysSeconds(std::string str) {
	std::chrono::sys_seconds tp = std::chrono::sys_seconds::min();
	std::stringstream ss(str);

	std::chrono::from_stream(ss, kDateTimeFormat.c_str(), tp);
	// if parse failed : return min();
	return tp;
}