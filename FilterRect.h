#pragma once

#include "Filter.h"
#include <string>
#include <iostream>
#include <fstream>

class FilterRect {
public:
	Filter getFilter() const;
	float getHBeg() const;
	float getWBeg() const;
	float getHEnd() const;
	float getWEnd() const;

	bool parseLine(const std::string& str);

	static FilterRect createInstance(const std::string& str);
	static FilterRect createInstance(const std::string& fName,
		const float hBeg, const float hEnd,
		const float wBeg, const float wEnd);

private:
	FilterRect();
	FilterRect(const Filter flt, const float hB,
		const float wB, const float hE,
		const float wE);

	Filter filter;
	float hBeg;
	float wBeg;
	float hEnd;
	float wEnd;	
};