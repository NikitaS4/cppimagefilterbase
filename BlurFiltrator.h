#pragma once
#include "Filtrator.h"

class BlurFiltrator : public Filtrator {
public:
	virtual void apply(RealRect& area, image_data& image);
	virtual Filter getFilterType() const;
protected:
	static const Filter f_type = Filter::BLUR;
private:
	unsigned int kerSize = 3;
};