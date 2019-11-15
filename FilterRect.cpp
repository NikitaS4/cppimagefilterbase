#include "FilterRect.h"

#include <vector>
#include <iostream>

bool FilterRect::parseLine(const std::string& str) 
{
	unsigned int spacePos;
	for (spacePos = 0; str[spacePos] != ' ' && str[spacePos] != '\0' && str[spacePos] != '\n'; ++spacePos);
	std::string fWord = str.substr(0, spacePos); //filter word
	filter = FilterHelper::parse(fWord); //string to filter

	std::string curWord;
	std::vector<float*> params { &hBeg, &wBeg, &hEnd, &wEnd }; //to iterate
	unsigned int beg = spacePos + 1; //access violation ?
	unsigned int end = beg;
	for (unsigned int i = 0; i < params.size(); ++i) {
		if (end >= str.size()) {
			//the config is wrong
			return false;
		}
		for (end = beg; str[end] != ' ' && str[end] != '\n' && str[end] != '\0'; ++end);
		curWord = str.substr(beg, end - 1); //end is space
		*(params[i]) = std::stoi(curWord); //convert
			beg = end + 1; //for next iteration
	}

	return true;
}

Filter FilterRect::getFilter() const {
	return filter;
}

float FilterRect::getHBeg() const {
	return hBeg;
}

float FilterRect::getWBeg()  const {
	return wBeg;
}

float FilterRect::getHEnd() const {
	return hEnd;
}

float FilterRect::getWEnd() const {
	return wEnd;
}

FilterRect FilterRect::createInstance(const std::string& str) {
	FilterRect ans;
	ans.parseLine(str);
	return ans;
}

FilterRect FilterRect::createInstance(const std::string& fName,
	const float hBeg, const float hEnd,
	const float wBeg, const float wEnd) {
	Filter flt = FilterHelper::parse(fName); //string to filter	

	return FilterRect(flt, hBeg, wBeg, hEnd, wEnd);
}

FilterRect::FilterRect(const Filter flt, const float hB,
	const float wB, const float hE,
	const float wE) : filter(flt), hBeg(hB), hEnd(hE),
	wBeg(wB), wEnd(wE) {}

FilterRect::FilterRect() {}