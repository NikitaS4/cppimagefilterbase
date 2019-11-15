#include "Filter.h"


Filter FilterHelper::parse(const std::string& str) {
	if (str == "Red") {
		return Filter::RED;
	}
	else if (str == "Blur") {
		return Filter::BLUR;
	}
	else if (str == "Edge") {
		return Filter::EDGE;
	}
	else if (str == "Threshold") {
		return Filter::THRESHOLD;
	}
	else if (str == "FancyBlur") {
		return Filter::FANCY_BLUR;
	}
	else if (str == "BW") {
		return Filter::BW;
	}
	else if (str == "Overflow") {
		return Filter::OVER;
	}
		return Filter::UNDEFINED;
}