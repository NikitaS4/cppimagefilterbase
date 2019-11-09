#pragma once

#include "Filtrator.h"

class RedFiltrator : public Filtrator {
public:
	void apply(RealRect& area, image_data& image);
	Filter getFilterType() const;
private:
	static const Filter f_type = Filter::RED;
};