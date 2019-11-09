#include "ImagePixels.h"

ImagePixels ImagePixels::createImage(const image_data& imData) {
	return ImagePixels(imData);
}

image_data& ImagePixels::returnImage() {
	return rawImage;
}

PNGCortege ImagePixels::getPixel(int w, int h) {
	return PNGCortege(&(rawImage.pixels[(h * rawImage.w + w) * rawImage.compPerPixel]));
}

unsigned int ImagePixels::getH() {
	return rawImage.h;
}

unsigned int ImagePixels::getW() {
	return rawImage.w;
}