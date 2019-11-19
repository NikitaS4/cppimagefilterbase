#pragma once

#include <string>

enum class Filter {
	UNDEFINED = 0,
	RED = 1,
	EDGE,
	THRESHOLD,
	FANCY_THRESHOLD,
	BLUR,
	FANCY_BLUR,
	BW,
	OVER,
	SIZE
};

class FilterHelper {
public:
	static Filter parse(const std::string& str);
};