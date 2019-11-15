#include "Convolution.h"
#include "ImagePixels.h"

#include <vector>
#include <iostream>

Convolution::Convolution(unsigned int kerSize, ConvStrategy* strategy)
	: kernel(kerSize) {
	strategy->fillKernel(kernel);
}

void Convolution::printKernel() {
	std::cout << "kernel:\n===========\n";
	kernel.print();
	std::cout << "===========\n";
}

void Convolution::apply(std::vector<std::vector<double>>& image) {
	std::vector<std::vector<double>> curImPart;
	unsigned int kerSize = kernel.getSize();
	curImPart.resize(kerSize);

	for (unsigned int i = 0; i < kerSize; ++i) {
		curImPart[i].resize(kerSize);
	}	

	std::vector<std::vector<double>> newImage;
	std::vector<double> curVec;
	for (unsigned int i = 0; i < image.size(); ++i) {		
		for (unsigned int j = 0; j < image[i].size(); ++j) {
			curVec.push_back(image[i][j]);
		}
		newImage.push_back(curVec);
		curVec.clear();
	}

	auto wLim = image.size();
	auto hLim = image[0].size();

	unsigned int bias = (kerSize - 1) / 2;

	for (unsigned int curH = 0; curH < hLim; ++curH) {
		for (unsigned int curW = 0; curW < wLim; ++curW) {
			for (unsigned int kerW = 0; kerW < kerSize; ++kerW) {
				for (unsigned int kerH = 0; kerH < kerSize; ++kerH) {
					if (kerH + curH < bias || (long long)kerH + curH - bias >= (long long)hLim ||
						kerW + curW < bias || (long long)kerW + curW - bias >= (long long)wLim) {
						curImPart[kerW][kerH] = 0;
					}
					else {
						curImPart[kerW][kerH] =
							image[(unsigned)((double)curW - bias + kerW)][(unsigned)((double)curH - bias + kerH)];
					}
				}
			}
			newImage[curW][curH] = kernel.apply(curImPart);
		}
	}

	std::swap(image, newImage); //to return new image		
}