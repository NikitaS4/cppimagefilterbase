#pragma once

#include "ConvKer.h"
#include "RealRect.h"
#include "ConvStrategy.h"
#include "png_toolkit.h"


class Convolution {
public:
	Convolution(unsigned int kerSize, ConvStrategy* strategy);

	void apply(std::vector<std::vector<double>>& image);
private:
	Convolution() = delete;	
	ConvKer kernel;
};