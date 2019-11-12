#pragma once
#include "Filtrator.h"

class BWFiltrator : public Filtrator {
public:
	void apply(RealRect& area, image_data& image);
	Filter getFilterType() const;
protected:
	static const Filter f_type = Filter::BW;
private:
	static double compress(const double red, const double green, const double blue);
};