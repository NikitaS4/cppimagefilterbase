#pragma once
#include <map>
#include "Filter.h"
#include "RealRect.h"
#include "Filtrator.h"
#include "png_toolkit.h"

class FilterBase {
public:
	FilterBase();
	void launchFilter(Filter filter, RealRect& real, image_data& imageData);
	~FilterBase();
private:
	std::map<Filter, Filtrator*> filterMap;
};