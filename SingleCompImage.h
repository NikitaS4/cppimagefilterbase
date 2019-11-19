#pragma once

#include <vector>
#include "ImagePixels.h"
#include "RealRect.h"

class SingleCompImage {
public:

	SingleCompImage(ImagePixels& imPxls, RealRect& area);	

	class Proxy {
	public:
		double& operator[](unsigned int h) {
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
		using mtx_double = std::vector<std::vector<double>>;
		Proxy() = delete;
		Proxy(mtx_double* pixMtx, unsigned int prevInd) :
		pix(pixMtx), w(prevInd) {};				
		unsigned int w;		
		mtx_double* pix;
	};

	Proxy operator[] (unsigned int w) {
		return Proxy(&pixels, w);
	}

	std::vector<std::vector<double>>& getMtx();

	void toBWImage(ImagePixels& imPxls, RealRect& area);

	unsigned int getW();
	unsigned int getH();
private:
	SingleCompImage();
	using mtx_double = std::vector<std::vector<double>>;
	mtx_double pixels;
	static double compress(const double red, const double green, const double blue);	
};