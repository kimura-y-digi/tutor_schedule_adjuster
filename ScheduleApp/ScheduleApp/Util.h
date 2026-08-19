#pragma once

#include <chrono>
#include <string>
#include <vector>


class Util
{
public:
	static std::string sysSecondsToStr(std::chrono::sys_seconds seconds);
	static std::chrono::sys_seconds strToSysSeconds(std::string str);
	static std::string vectorIntToStr(const std::vector<int> array);

private:
	static const std::string kDateTimeFormat;
};