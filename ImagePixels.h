#pragma once

#include "png_toolkit.h"

class ImagePixels {
public:
	static ImagePixels createImage(const image_data& imData);
	image_data& returnImage();

	unsigned char* getPixel(int w, int h);

	class Proxy {
	public:
		Proxy(unsigned int _i, image_data* ptr)
			: rIptr(ptr), i(_i) {}

		unsigned char* operator[](int h) {
			return &(rIptr->pixels[(h * rIptr->w + i) * rIptr->compPerPixel]);
		}

	private:
		unsigned int i;
		image_data* rIptr;
	};
	
	Proxy operator[](int w) {
		return Proxy(w, &rawImage);
	}

private:
	ImagePixels() = delete;
	ImagePixels(const image_data& imData) : rawImage(imData) {}

	image_data rawImage;
};