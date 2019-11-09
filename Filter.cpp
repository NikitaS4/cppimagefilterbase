#include "Filter.h"


Filter FilterHelper::parse(std::string& str) {
	if (str == "Red") {
		return Filter::RED;
	}
	else if (str == "Blur") {
		return Filter::BLUR;
	}
		return Filter::UNDEFINED;
}