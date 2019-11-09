#pragma once

#include "ConvKer.h"


class ConvStrategy {
public:
	virtual void fillKernel(ConvKer& kernel) = 0;
};