#include "SingleCompImage.h"
#include <iostream>

unsigned int SingleCompImage::compress(const unsigned int red, const unsigned int green, const unsigned int blue) {
	static const int factors[3] = { 3, 6, 1 };	
	return (factors[0] * red + factors[1] * green + factors[2] * blue) / 10;
}

std::vector<std::vector<unsigned int>>& SingleCompImage::getMtx() {
	return pixels;
}

SingleCompImage::SingleCompImage(ImagePixels& imPxls,
	RealRect& area) {
	auto areaH = area.hEnd - area.hBeg;
	auto areaW = area.wEnd - area.wBeg;

	pixels.resize(areaW);

	unsigned int red = 0;
	unsigned int green = 0;
	unsigned int blue = 0;
	
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