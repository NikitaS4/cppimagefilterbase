#pragma once

#include "Filter.h"
#include <string>
#include <iostream>
#include <fstream>

class FilterRect {
public:
	Filter getFilter() const;
	unsigned int getHBeg() const;
	unsigned int getWBeg() const;
	unsigned int getHEnd() const;
	unsigned int getWEnd() const;

	bool parseLine(const std::string& str);

	static FilterRect createInstance(const std::string& str);
	static FilterRect createInstance(const std::string& fName,
		const unsigned int hBeg, const unsigned int hEnd,
		const unsigned int wBeg, const unsigned int wEnd);

private:
	FilterRect();
	FilterRect(const Filter flt, const unsigned int hB,
		const unsigned int wB, const unsigned int hE,
		const unsigned int wE);

	Filter filter;
	unsigned int hBeg;
	unsigned int wBeg;
	unsigned int hEnd;
	unsigned int wEnd;	
};