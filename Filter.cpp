#include "Filter.h"


Filter FilterHelper::parse(const std::string& str) {
	if (str == "Red") {
		return Filter::RED;
	}
	else if (str == "Blur") {
		return Filter::BLUR;
	}
		return Filter::UNDEFINED;
}