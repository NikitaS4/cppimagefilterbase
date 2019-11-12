#pragma once

#include <vector>
#include "ImagePixels.h"
#include "RealRect.h"

class SingleCompImage {
public:

	SingleCompImage(ImagePixels& imPxls, RealRect& area);	

	class Proxy {
	public:
		double& operator[](unsigned int j) {
			return (*pix)[i][j];
		}
	private:
		friend SingleCompImage;
		using mtx_double = std::vector<std::vector<double>>;
		Proxy() = delete;
		Proxy(mtx_double* pixMtx, unsigned int prevInd) :
		pix(pixMtx), i(prevInd) {};				
		unsigned int i;		
		mtx_double* pix;
	};

	Proxy operator[] (unsigned int i) {
		return Proxy(&pixels, i);
	}

	std::vector<std::vector<double>>& getMtx();

	void toBWImage(ImagePixels& imPxls, RealRect& area);
private:
	SingleCompImage();
	using mtx_double = std::vector<std::vector<double>>;
	mtx_double pixels;
	static double compress(const double red, const double green, const double blue);	
};