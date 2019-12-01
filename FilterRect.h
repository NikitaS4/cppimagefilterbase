#pragma once

#include "Filter.h"
#include <string>
#include <iostream>
#include <fstream>
#include "Settings.h"

class FilterRect {
public:
	Filter getFilter() const;
	CONFIG_RECT_TYPE getHBeg() const;
	CONFIG_RECT_TYPE getWBeg() const;
	CONFIG_RECT_TYPE getHEnd() const;
	CONFIG_RECT_TYPE getWEnd() const;

	bool parseLine(const std::string& str);

	static FilterRect createInstance(const std::string& str);
	static FilterRect createInstance(const std::string& fName,
		const CONFIG_RECT_TYPE hBeg, const CONFIG_RECT_TYPE hEnd,
		const CONFIG_RECT_TYPE wBeg, const CONFIG_RECT_TYPE wEnd);

private:
	FilterRect();
	FilterRect(const Filter flt, const CONFIG_RECT_TYPE hB,
		const CONFIG_RECT_TYPE wB, const CONFIG_RECT_TYPE hE,
		const CONFIG_RECT_TYPE wE);

	Filter filter;
	CONFIG_RECT_TYPE hBeg;
	CONFIG_RECT_TYPE wBeg;
	CONFIG_RECT_TYPE hEnd;
	CONFIG_RECT_TYPE wEnd;	
};