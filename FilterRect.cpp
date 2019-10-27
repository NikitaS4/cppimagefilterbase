#include "FilterRect.h"

bool FilterRect::parseLine(const std::string& str) 
{
	unsigned int spacePos;
	for (spacePos = 0; str[spacePos] != ' ' && str[spacePos] != '\0' && str[spacePos] != '\n'; ++spacePos);
	std::string fWord = str.substr(0, spacePos); //filter word
	filter = FilterHelper::parse(fWord); //string to filter

	std::string curWord;
	unsigned int* params[] = { &hBeg, &wBeg, &hEnd, &wEnd }; //to iterate
	unsigned int beg = spacePos + 1; //access violation ?
	unsigned int end;
	for (unsigned int i = 0; i < 4; ++i) {
		for (end = beg; str[end] != ' ' && str[end] != '\n' && str[end] != '\0'; ++end);
		curWord = str.substr(beg, end - 1); //end is space
		*params[i] = std::stoi(curWord); //convert
			beg = end + 1; //for next iteration
	}

	return true;
}

Filter FilterRect::getFilter() const {
	return filter;
}

unsigned int FilterRect::getHBeg() const {
	return hBeg;
}

unsigned int FilterRect::getWBeg()  const {
	return wBeg;
}

unsigned int FilterRect::getHEnd() const {
	return hEnd;
}

unsigned int FilterRect::getWEnd() const {
	return wEnd;
}

FilterRect FilterRect::createInstance(const std::string& str) {
	FilterRect ans;
	ans.parseLine(str);
	return ans;
}

FilterRect::FilterRect() {}