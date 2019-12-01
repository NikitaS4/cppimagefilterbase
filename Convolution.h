#pragma once

#include "ConvKer.h"
#include "RealRect.h"
#include "ConvStrategy.h"
#include "png_toolkit.h"
#include <vector>

class Convolution {
public:
	Convolution(unsigned int kerSize, ConvStrategy* strategy);

	void apply(std::vector<std::vector<unsigned int>>& image);
	void printKernel(); //for debug only
private:
	Convolution() = delete;	
	ConvKer kernel;
};