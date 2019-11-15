#pragma once

#include "Filtrator.h"

class OverflowFiltrator : public Filtrator { //blue overflow
public:
	void apply(RealRect& area, image_data& image);
	Filter getFilterType() const;
private:
	static const Filter f_type = Filter::OVER;
};