#include "ConfigParser.h"

void ConfigParser::initStrByStr(const std::string& fName) {
	std::ifstream input(fName);
	std::string curStr;

	while (!input.eof()) {
		std::getline(input, curStr);
		if (curStr != "") //to ignore empty lines
			rects.push_back(FilterRect::createInstance(curStr));
	}
}

void ConfigParser::initStream(const std::string& fName) {
	std::ifstream input(fName);
	
	if (!input)
		throw std::runtime_error("Can't open file");

	float hBeg;
	float hEnd;
	float wBeg;
	float wEnd;

	while (!input.eof()) {
		std::string filterName;		
		if (!(input >> filterName))
			return;
		if (!(input >> hBeg))
			return;
		if (!(input >> wBeg))
			return;
		if (!(input >> hEnd))
			return;
		if (!(input >> wEnd))
			return;
		rects.push_back(FilterRect::createInstance(filterName,
			hBeg, hEnd, wBeg, wEnd));
	}
}

std::vector<FilterRect>& ConfigParser::getRects() {
	return rects;
}
