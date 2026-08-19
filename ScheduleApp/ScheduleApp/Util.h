#pragma once

#include <chrono>
#include <string>
#include <sstream>
#include <vector>


class Util
{
public:
	static std::string sysSecondsToStr(std::chrono::sys_seconds seconds);
	static std::chrono::sys_seconds strToSysSeconds(std::string str);
	static std::string vectorIntToStr(const std::vector<int> array);
	static void test(std::ostringstream& oss);

private:
	static const std::string kDateTimeFormat;
};