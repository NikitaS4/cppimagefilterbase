#include "SingleCompImage.h"
#include <iostream>

double SingleCompImage::compress(const double red, const double green, const double blue) {
	static const double factors[3] = { 0.3, 0.6, 0.1 };	
	return factors[0] * red + factors[1] * green + factors[2] * blue;
}

std::vector<std::vector<double>>& SingleCompImage::getMtx() {
	return pixels;
}

SingleCompImage::SingleCompImage(ImagePixels& imPxls,
	RealRect& area) {
	auto areaH = area.hEnd - area.hBeg;
	auto areaW = area.wEnd - area.wBeg;

	pixels.resize(areaW);

	double red = 0;
	double green = 0;
	double blue = 0;
	
	for (unsigned int curW = area.wBeg, i = 0;
		curW < area.wEnd; ++curW, ++i) {
		pixels[i].resize(areaH);
		for (unsigned int curH = area.hBeg, j = 0;
			curH < area.hEnd; ++curH, ++j) {
			auto cortege = imPxls[curW][curH];
			red = cortege.getR();
			green = cortege.getG();
			blue = cortege.getB();
			pixels[i][j] = compress(red, green, blue);			
		}
	}
}

void SingleCompImage::toBWImage(ImagePixels& imPxls,
	RealRect& area) {
	for (unsigned int curW = area.wBeg, i = 0;
		curW < area.wEnd; ++curW, ++i) {
		for (unsigned int curH = area.hBeg, j = 0;
			curH < area.hEnd; ++curH, ++j) {
			auto cortege = imPxls[curW][curH];
			cortege.setR((unsigned char)pixels[i][j]);
			cortege.setG((unsigned char)pixels[i][j]);
			cortege.setB((unsigned char)pixels[i][j]);			
		}
	}
}

unsigned int SingleCompImage::getW() {
	return (unsigned int)(pixels[0].size());
}

unsigned int SingleCompImage::getH() {
	return (unsigned int)(pixels.size());
}