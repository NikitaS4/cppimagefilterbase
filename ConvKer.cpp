#include "ConvKer.h"


ConvKer::ConvKer(unsigned int dim) :
size(dim) {
	kernel.resize(dim);
	for (auto& it : kernel) {
		it.resize(dim);
	}
}


void ConvKer::put(unsigned int i, unsigned int j, double data) {
	kernel[i][j] = data;
}


unsigned int ConvKer::getSize() {
	return size;
}

void ConvKer::print() {
	for (unsigned int i = 0; i < size; ++i) {
		for (unsigned int j = 0; j < size; ++j) {
			std::cout << kernel[i][j] << " ";
		}
		std::cout << "\n";
	}
}

double ConvKer::apply(std::vector<std::vector<double>>& imagePart) {
	double ans = 0;
	if (imagePart.size() != size || imagePart[0].size() != size)
		throw std::runtime_error("convKer - apply => wrong dimensions");
	for (unsigned int i = 0; i < size; ++i) {
		for (unsigned int j = 0; j < size; ++j) {
			ans += imagePart[i][j] * kernel[i][j];
		}
	}
	return ans;
}



double ConvKer::sumApply(std::vector<std::vector<double>>& imagePart) {
	apply(imagePart);
	double sum = 0;
	for (auto& it : imagePart) {
		for (auto& curVoxel : it) {
			sum += curVoxel;
		}
	}
	return sum;
}