#pragma once

#include "png_toolkit.h"
#include "PNGCortege.h"

#include <iostream>

class ImagePixels {
public:
	static ImagePixels createImage(const image_data& imData);
	image_data& returnImage();

	PNGCortege getPixel(int w, int h);

	unsigned int getW();
	unsigned int getH();

	class Proxy {
	public:
		Proxy(unsigned int _i, image_data* ptr)
			: rIptr(ptr), i(_i) {}

		PNGCortege operator[](int h) {
			if (h >= rIptr->h) {				
				throw std::runtime_error("operator[][] -> too big h");
			}
			return PNGCortege(&(rIptr->pixels[(h * rIptr->w + i) * rIptr->compPerPixel]));
		}

	private:
		unsigned int i;
		image_data* rIptr;
	};
	
	Proxy operator[](int w) {
		if (w >= rawImage.w) {			
			throw std::runtime_error("operator[] -> too big w");
		}		
		return Proxy(w, &rawImage);
	}

private:
	ImagePixels() = delete;
	ImagePixels(const image_data& imData) : rawImage(imData) {}

	image_data rawImage;
};