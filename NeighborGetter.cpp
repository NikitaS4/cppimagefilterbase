#include "NeighborGetter.h"
#include <iostream>

NeighborGetter::NeighborGetter(SingleCompImage& im, unsigned int ar) :
	image(&im), area(ar) {}

inline unsigned int min(unsigned int left, unsigned int right) {
	return (left < right) ? (left) : (right);
}

std::vector<double> NeighborGetter::get(unsigned int w, 
	unsigned int h) {
	unsigned int bias = area / 2;
	unsigned int hLim = image->getH();
	unsigned int wLim = image->getW();
	std::vector<double> ans;
	for (unsigned int curW = (w > bias) ? (w - bias) : (0); curW < min(w + bias + area % 2, wLim); ++curW) {
		for (unsigned int curH = (h > bias) ? (h - bias) : (0); curH < min(h + bias + area % 2, hLim); ++curH) {					
			ans.push_back((*image)[curW][curH]);
		}
	}
	return ans;
}