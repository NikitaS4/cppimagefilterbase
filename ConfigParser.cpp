#include "ConfigParser.h"

void ConfigParser::init(const std::string& fName) {
	std::ifstream input(fName);
	std::string curStr;

	while (!input.eof()) {
		std::getline(input, curStr);
		rects.push_back(FilterRect::createInstance(curStr));
	}
}

std::vector<FilterRect>& ConfigParser::getRects() {
	return rects;
}
