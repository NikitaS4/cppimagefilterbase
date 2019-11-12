#pragma once
#include "ConvStrategy.h"

class ConvEdgeStrategy : public ConvStrategy {
public:
	virtual void fillKernel(ConvKer& kernel);
};