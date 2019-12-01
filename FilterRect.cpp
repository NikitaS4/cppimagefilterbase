#include "FilterRect.h"

#include <vector>
#include <iostream>

static inline CONFIG_RECT_TYPE strToNumber(std::string& str) {
#ifdef CONFIG_RECT_IS_INTEGER
	return std::stoi(str);
#else
	return std::stof(str);
#endif /* CONFIG_RECT_IS_INTEGER */
}

bool FilterRect::parseLine(const std::string& str) 
{
	unsigned int spacePos;
	for (spacePos = 0; str[spacePos] != ' ' && str[spacePos] != '\0' && str[spacePos] != '\n'; ++spacePos);
	std::string fWord = str.substr(0, spacePos); //filter word
	filter = FilterHelper::parse(fWord); //string to filter

	std::string curWord;
	std::vector<CONFIG_RECT_TYPE*> params { &hBeg, &wBeg, &hEnd, &wEnd }; //to iterate
	unsigned int beg = spacePos + 1; //access violation ?
	unsigned int end = beg;
	for (unsigned int i = 0; i < params.size(); ++i) {
		if (end >= str.size()) {
			//the config is wrong
			return false;
		}
		for (end = beg; str[end] != ' ' && str[end] != '\n' && str[end] != '\0'; ++end);
		curWord = str.substr(beg, end - 1); //end is space
		*(params[i]) = strToNumber(curWord); //convert
			beg = end + 1; //for next iteration
	}

	return true;
}

Filter FilterRect::getFilter() const {
	return filter;
}

CONFIG_RECT_TYPE FilterRect::getHBeg() const {
	return hBeg;
}

CONFIG_RECT_TYPE FilterRect::getWBeg()  const {
	return wBeg;
}

CONFIG_RECT_TYPE FilterRect::getHEnd() const {
	return hEnd;
}

CONFIG_RECT_TYPE FilterRect::getWEnd() const {
	return wEnd;
}

FilterRect FilterRect::createInstance(const std::string& str) {
	FilterRect ans;
	ans.parseLine(str);
	return ans;
}

FilterRect FilterRect::createInstance(const std::string& fName,
	const CONFIG_RECT_TYPE hBeg, const CONFIG_RECT_TYPE hEnd,
	const CONFIG_RECT_TYPE wBeg, const CONFIG_RECT_TYPE wEnd) {
	Filter flt = FilterHelper::parse(fName); //string to filter	

	return FilterRect(flt, hBeg, wBeg, hEnd, wEnd);
}

FilterRect::FilterRect(const Filter flt, const CONFIG_RECT_TYPE hB,
	const CONFIG_RECT_TYPE wB, const CONFIG_RECT_TYPE hE,
	const CONFIG_RECT_TYPE wE) : filter(flt), hBeg(hB), hEnd(hE),
	wBeg(wB), wEnd(wE) {}

FilterRect::FilterRect() {}