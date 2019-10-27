#pragma once

#include "FilterRect.h"
#include <string>
#include <fstream>
#include <vector>

class ConfigParser {
public:
	ConfigParser() {}
	void init(const std::string& fName);
	std::vector<FilterRect>& getRects();
private:
	std::vector<FilterRect> rects;
};