#pragma once

#include "FilterRect.h"
#include "Filtrator.h"
#include "png_toolkit.h"

class RectAdapter {
public:
	static RealRect frectToReal(const FilterRect& frect,
		const image_data& image);
};