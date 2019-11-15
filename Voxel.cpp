#include "Voxel.h"
#include <iostream>

Voxel::Voxel(SingleCompImage* parentImage,
	unsigned int firstPixW, unsigned int firstPixH,
	unsigned int dimW, unsigned int dimH) :
w(dimW), h(dimH), parent(parentImage),
startW(firstPixW), startH(firstPixH) {}

void Voxel::doForEach(std::function<void(double&)> operation,
	std::function<bool(double&)> condition) {	
	for (unsigned int realW = startW, wNum = 0;
		wNum < w && realW < parent->getW(); ++wNum, ++realW) {
		for (unsigned int realH = startH, hNum = 0;
			hNum < h && realH < parent->getH(); ++hNum, ++realH) {
			double& current = (*parent)[realH][realW];
			if (condition(current)) {
				operation(current);
			}
		}
	}
}

std::vector<double> Voxel::get() {
	std::vector<double> ans;
	auto condition = [](double&)->bool { return true; };
	auto getter = [&ans](double& current)->void {
		ans.push_back(current);
	};
	doForEach(getter, condition);
	return ans;
}

void Voxel::put(std::vector<double>& newPixels) {
	unsigned int i = 0;
	auto condition = [](double&)->bool { return true; };	
	auto setter = [&newPixels, &i](double& current)mutable->void {
		if (i >= newPixels.size())
			throw std::runtime_error("Put - wrong index");
		current = newPixels[i++];
	};
	doForEach(setter, condition);
}