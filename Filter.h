#pragma once

#include <string>

enum class Filter {
	UNDEFINED,
	RED
};

class FilterHelper {
public:
	static Filter parse(std::string& str);
};