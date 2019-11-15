#include "Fragmentation.h"

Fragmentation::Fragmentation(unsigned int w, unsigned int h, 
	SingleCompImage& image) : wVox(w),
	hVox(h), imIntensity(&image) {	
	maxW = image.getW() / w;
	maxH = image.getH() / h;
	}

unsigned int Fragmentation::getWVox() {
	return wVox;
}

unsigned int Fragmentation::getHVox() {
	return hVox;
}

void Fragmentation::doForEach(std::function<void(Voxel&)>& operation,
	std::function<bool(Voxel&)>& condition) {
	for (unsigned int w = 0; w < maxW; ++w) {
		for (unsigned int h = 0; h < maxH; ++h) {
			Voxel current = (*this)[w][h];
			if (condition(current)) {
				operation(current);
			}
		}
	}
}