#pragma once
#include "Filtrator.h"

class FancyBlurFiltrator : public Filtrator {
public:
	virtual void apply(RealRect& area, image_data& image);
	virtual Filter getFilterType() const;
protected:
	static const Filter f_type = Filter::FANCY_BLUR;
private:
	unsigned int kerSize = 3;
};