#pragma once

#include <string>

enum class Filter {
	UNDEFINED,
	RED,
	EDGE,
	THRESHOLD,
	BLUR,
	FANCY_BLUR,
	BW
};

class FilterHelper {
public:
	static Filter parse(const std::string& str);
};