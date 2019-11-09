#include "Convolution.h"
#include "ImagePixels.h"

#include <vector>
#include <iostream>

Convolution::Convolution(unsigned int kerSize, ConvStrategy* strategy)
	: kernel(kerSize) {
	strategy->fillKernel(kernel);
}


void Convolution::apply(std::vector<std::vector<double>>& image) {
	std::vector<std::vector<double>> curImPart;
	unsigned int kerSize = kernel.getSize();
	curImPart.resize(kerSize);

	for (unsigned int i = 0; i < kerSize; ++i) {
		curImPart[i].resize(kerSize);
	}	
	std::vector<std::vector<double>> newImage;

	for (unsigned int i = 0; i < image.size(); ++i) {
		std::vector<double> curVec;
		for (unsigned int j = 0; j < image[i].size(); ++j) {
			curVec.push_back(image[i][j]);
		}
		newImage.push_back(curVec);
	}

	auto wLim = image.size();
	auto hLim = image[0].size();

	for (int curH = 0; curH < hLim; ++curH) {
		for (int curW = 0; curW < wLim; ++curW) {
			for (int kerH = -(int)kerSize / 2; kerH < (int)kerSize / 2; ++kerH) {
				for (int kerW = -(int)kerSize / 2; kerW < (int)kerSize / 2; ++kerW) {
					if (kerH + curH < 0 || (long long)kerH + curH >= (long long)hLim ||
						kerW + curW < 0|| (long long)kerW + curW >= (long long)wLim) {
						curImPart[(long long)kerW + kerSize / 2][(long long)kerH + kerSize / 2] = 0;
					}
					else {						
						curImPart[(long long)kerW + kerSize / 2][(long long)kerH + kerSize / 2] = 
							image[(long long)kerW + curW][curH + (long long)kerH];
					}					
				}
			}
			newImage[curW][curH] = kernel.apply(curImPart);
		}
	}	
	std::swap(image, newImage); //to return new image
}