#pragma once

#include <string>

enum class Filter {
	UNDEFINED,
	RED,
	EDGE,
	THRESHOLD,
	BLUR
};

class FilterHelper {
public:
	static Filter parse(const std::string& str);
};