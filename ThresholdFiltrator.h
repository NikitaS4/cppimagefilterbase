#pragma once
#include "Filtrator.h"
#include "Settings.h"

class ThresholdFiltrator : public Filtrator {
public:
	virtual void apply(RealRect& area, image_data& image);
	virtual Filter getFilterType() const;	
protected:
	static const Filter f_type = Filter::THRESHOLD;
	static const unsigned int localityArea = THRESHOLD_LOCALITY_AREA;
};