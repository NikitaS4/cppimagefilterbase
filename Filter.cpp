#include "Filter.h"


Filter FilterHelper::parse(std::string& str) {
	if (str == "Red") {
		return Filter::RED;
	}
	else
		return Filter::UNDEFINED;
}