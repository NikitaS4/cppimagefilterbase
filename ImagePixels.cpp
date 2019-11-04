#include "ImagePixels.h"

ImagePixels ImagePixels::createImage(const image_data& imData) {
	return ImagePixels(imData);
}

image_data& ImagePixels::returnImage() {
	return rawImage;
}

unsigned char* ImagePixels::getPixel(int w, int h) {
	return &(rawImage.pixels[(h * rawImage.w + w) * rawImage.compPerPixel]);
}