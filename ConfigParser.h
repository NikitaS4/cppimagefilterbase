#pragma once

#include "FilterRect.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

class ConfigParser {
public:
	ConfigParser() {}
	void initStrByStr(const std::string& fName);
	void initStream(const std::string& fName);
	std::vector<FilterRect>& getRects();
private:
	std::vector<FilterRect> rects;
};