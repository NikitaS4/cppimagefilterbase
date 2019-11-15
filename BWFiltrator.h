#pragma once
#include "Filtrator.h"

class BWFiltrator : public Filtrator {
public:
	void apply(RealRect& area, image_data& image);
	Filter getFilterType() const;
protected:
	static const Filter f_type = Filter::BW;
};