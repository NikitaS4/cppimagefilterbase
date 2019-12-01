#include "ConvKer.h"


ConvKer::ConvKer(unsigned int dim) :
size(dim) {
	kernel.resize(dim);
	for (auto& it : kernel) {
		it.resize(dim);
	}
}


void ConvKer::put(unsigned int i, unsigned int j, int data) {
	kernel[i][j] = data;
}


unsigned int ConvKer::getSize() {
	return size;
}

void ConvKer::setNorm(unsigned int divisor) {
	normalizationDivisor = divisor;
}

void ConvKer::print() {
	for (unsigned int i = 0; i < size; ++i) {
		for (unsigned int j = 0; j < size; ++j) {
			std::cout << kernel[i][j] << " ";
		}
		std::cout << "\n";
	}
}

unsigned int ConvKer::apply(std::vector<std::vector<unsigned int>>& imagePart) {
	int ans = 0;
	if (imagePart.size() != size || imagePart[0].size() != size)
		throw std::runtime_error("convKer - apply => wrong dimensions");
	for (unsigned int i = 0; i < size; ++i) {
		for (unsigned int j = 0; j < size; ++j) {
			ans += imagePart[i][j] * kernel[i][j];
		}
	}

	ans /= normalizationDivisor;

	if (ans < 0 || ans >= 256) {
		ans = 0;
	}
	return ans;
}



unsigned int ConvKer::sumApply(std::vector<std::vector<unsigned int>>& imagePart) {
	apply(imagePart);
	unsigned int sum = 0;
	for (auto& it : imagePart) {
		for (auto& curVoxel : it) {
			sum += curVoxel;
		}
	}
	return sum;
}