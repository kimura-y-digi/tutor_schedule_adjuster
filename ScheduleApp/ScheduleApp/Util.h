#pragma once

#include <chrono>
#include <string>


class Util
{
public:
	static std::string sysSecondsToStr(std::chrono::sys_seconds seconds);
	static std::chrono::sys_seconds strToSysSeconds(std::string str);

private:
	static const std::string kDateTimeFormat;
};