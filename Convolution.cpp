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

	/*for (int curH = 0; curH < hLim; ++curH) {
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
	}	*/

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