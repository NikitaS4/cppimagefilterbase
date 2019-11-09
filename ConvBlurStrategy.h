#pragma once
#include "ConvStrategy.h"

class ConvBlurStrategy : public ConvStrategy {
public:
	virtual void fillKernel(ConvKer& kernel);
};