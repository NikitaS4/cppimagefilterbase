#pragma once
#include "ConvStrategy.h"

class ConvFancyBlurStrategy : public ConvStrategy {
public:
	virtual void fillKernel(ConvKer& kernel);
};