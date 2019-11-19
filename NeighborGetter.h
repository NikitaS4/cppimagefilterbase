#pragma once

#include "SingleCompImage.h"
#include <vector>

class NeighborGetter {
public:
	NeighborGetter(SingleCompImage& im, unsigned int ar);
	std::vector<double> get(unsigned int w, unsigned int h);
private:	
	SingleCompImage* image;
	unsigned int area = 5;
};