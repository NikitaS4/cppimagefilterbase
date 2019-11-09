#pragma once

#include <string>

enum class Filter {
	UNDEFINED,
	RED,
	BLUR
};

class FilterHelper {
public:
	static Filter parse(std::string& str);
};