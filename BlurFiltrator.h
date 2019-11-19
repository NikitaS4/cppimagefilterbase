#pragma once
#include "Filtrator.h"
#include "ConvBlurStrategy.h"

class BlurFiltrator : public Filtrator {
public:
	BlurFiltrator(ConvStrategy* strategy = new ConvBlurStrategy()) : convStrategy(strategy){}

	virtual void apply(RealRect& area, image_data& image);
	virtual Filter getFilterType() const;

	virtual ~BlurFiltrator(){
		delete convStrategy; 
	}
protected:
	static const Filter f_type = Filter::BLUR;
	ConvStrategy* convStrategy;
	unsigned int kerSize = 3;
};