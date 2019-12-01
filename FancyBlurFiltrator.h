#pragma once
#include "BlurFiltrator.h"
#include "ConvFancyBlurStrategy.h"
#include "Settings.h"

class FancyBlurFiltrator : public BlurFiltrator {
public:
	FancyBlurFiltrator() : BlurFiltrator(new ConvFancyBlurStrategy()) {
		kerSize = FANCY_BLUR_CONV_KER_SIZE;
	}
	
	virtual Filter getFilterType() const;

	//virtual ~FancyBlurFiltrator() {
	//	delete convStrategy;
	//}
protected:
	static const Filter f_type = Filter::FANCY_BLUR;	
};