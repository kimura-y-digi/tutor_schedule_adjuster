#pragma once

#include <string>
#include <vector>


struct EventCondition {
	int use_minutes = 0;
	std::vector<int> participants = {};
	std::string start_date;
	std::string end_date;
	std::string start_time;
	std::string end_time;
};