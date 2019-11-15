#pragma once
#include "BlurFiltrator.h"
#include "ConvFancyBlurStrategy.h"

class FancyBlurFiltrator : public BlurFiltrator {
public:
	FancyBlurFiltrator() : BlurFiltrator(new ConvFancyBlurStrategy()) {}
	
	virtual Filter getFilterType() const;

	//virtual ~FancyBlurFiltrator() {
	//	delete convStrategy;
	//}
protected:
	static const Filter f_type = Filter::FANCY_BLUR;	
private:
	unsigned int kerSize = 3;
};