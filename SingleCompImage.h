#pragma once

#include <vector>
#include "ImagePixels.h"
#include "RealRect.h"

class SingleCompImage {
public:

	SingleCompImage(ImagePixels& imPxls, RealRect& area);	

	class Proxy {
	public:
		unsigned int& operator[](unsigned int h) {
			if (h > (*pix).size()) {
				throw std::runtime_error("SingleCompImage[][h > size]");
			}
			if (w > (*pix)[h].size()) {
				throw std::runtime_error("SingleCompImage[w > size][]");
			}			
			return (*pix)[h][w];
		}
	private:
		friend SingleCompImage;
		using mtx_double = std::vector<std::vector<unsigned int>>;
		Proxy() = delete;
		Proxy(mtx_double* pixMtx, unsigned int prevInd) :
		pix(pixMtx), w(prevInd) {};				
		unsigned int w;		
		mtx_double* pix;
	};

	Proxy operator[] (unsigned int w) {
		return Proxy(&pixels, w);
	}

	std::vector<std::vector<unsigned int>>& getMtx();

	void toBWImage(ImagePixels& imPxls, RealRect& area);

	unsigned int getW();
	unsigned int getH();
private:
	SingleCompImage();
	using mtx_double = std::vector<std::vector<unsigned int>>;
	mtx_double pixels;
	static unsigned int compress(const unsigned int red, const unsigned int green, const unsigned int blue);
};