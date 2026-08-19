#include "Util.h"

#include <chrono>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


const std::string Util::kDateTimeFormat = "%Y-%s-%d %H:%M:%S";

std::string Util::sysSecondsToStr(std::chrono::sys_seconds seconds) {
	std::string ret;
	try {
		ret = std::format("{}", kDateTimeFormat.c_str(), seconds);
	}
	catch (...) {
		std::cerr << "FAILED : Util::sysSecondsToStr()" << std::endl;
	}

	return ret;
}

std::chrono::sys_seconds Util::strToSysSeconds(std::string str) {
	std::chrono::sys_seconds tp = std::chrono::sys_seconds::min();
	std::stringstream ss(str);

	std::chrono::from_stream(ss, kDateTimeFormat.c_str(), tp);
	if (tp == std::chrono::sys_seconds::min()) {
		std::cerr << "FAILED : Util::strToSysSeconds()" << std::endl;
	}

	return tp;
}

std::string Util::vectorIntToStr(const std::vector<int> array) {
	std::string ret;
	for (int i = 0; i < array.size(); ++i) {
		ret += array.at(i);
		if (i != (array.size() - 1)) {
			ret += " ";
		}
	}

	return ret;
}