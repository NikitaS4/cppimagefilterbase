#pragma once

#include "png_toolkit.h"
#include "Filter.h"

#include "RealRect.h"

class Filtrator {
public:
	virtual void apply(RealRect& area, image_data& image) = 0;
	virtual Filter getFilterType() const = 0;
protected:
	Filter f_type = Filter::UNDEFINED;
};