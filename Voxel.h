#pragma once

#include "SingleCompImage.h"
#include <functional>
#include <vector>

class Voxel {
public:
	
	Voxel(SingleCompImage* parentImage,
		unsigned int firstPixW, unsigned int firstPixH,
		unsigned int dimW, unsigned int dimH);

	void doForEach(std::function<void(unsigned int&)> operation,
		std::function<bool(unsigned int&)> condition); //iterator - for each pixel in the voxel

	std::vector<unsigned int> get();
	void put(std::vector<unsigned int>& newPixels);

private:
	unsigned int w;
	unsigned int h;

	//to have an access to each pixel in the voxel
	SingleCompImage* parent;
	unsigned int startW;
	unsigned int startH;
};