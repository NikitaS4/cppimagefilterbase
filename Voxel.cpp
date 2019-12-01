#include "Voxel.h"
#include <iostream>

Voxel::Voxel(SingleCompImage* parentImage,
	unsigned int firstPixW, unsigned int firstPixH,
	unsigned int dimW, unsigned int dimH) :
w(dimW), h(dimH), parent(parentImage),
startW(firstPixW), startH(firstPixH) {}

void Voxel::doForEach(std::function<void(unsigned int&)> operation,
	std::function<bool(unsigned int&)> condition) {
	for (unsigned int realW = startW, wNum = 0;
		wNum < w && realW < parent->getW(); ++wNum, ++realW) {
		for (unsigned int realH = startH, hNum = 0;
			hNum < h && realH < parent->getH(); ++hNum, ++realH) {
			unsigned int& current = (*parent)[realW][realH];
			if (condition(current)) {
				operation(current);
			}
		}
	}
}

std::vector<unsigned int> Voxel::get() {
	std::vector<unsigned int> ans;
	auto condition = [](unsigned int&)->bool { return true; };
	auto getter = [&ans](unsigned int& current)->void {
		ans.push_back(current);
	};
	doForEach(getter, condition);
	return ans;
}

void Voxel::put(std::vector<unsigned int>& newPixels) {
	unsigned int i = 0;
	auto condition = [](unsigned int&)->bool { return true; };
	auto setter = [&newPixels, &i](unsigned int& current)mutable->void {
		if (i >= newPixels.size())
			throw std::runtime_error("Put - wrong index");
		current = newPixels[i++];
	};
	doForEach(setter, condition);
}