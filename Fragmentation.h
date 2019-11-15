#pragma once
#include "SingleCompImage.h"
#include "RealRect.h"
#include "Voxel.h"
#include <iostream>
#include <functional>

class Fragmentation {	
public:	

	Fragmentation(unsigned int w, unsigned int h,
		SingleCompImage& image);

	unsigned int getWVox();
	unsigned int getHVox();	

	class Proxy {
	public:
		Proxy(unsigned int parentW, Fragmentation* fragParent) :
			w(parentW), parent(fragParent) {}

		Voxel operator[](unsigned int h) {
			if (h >= parent->maxH)
				throw std::runtime_error("Fragmentation: Index out of bound");
			return Voxel(parent->imIntensity, w * parent->wVox,
				h * parent->hVox, parent->wVox, parent->hVox);
		}
	private:
		Fragmentation* parent;
		unsigned int w;
	};

	Proxy operator[](unsigned int w) {
		if (w >= maxW)
			throw std::runtime_error("Fragmentation: Index out of bound");
		return Proxy(w, this);
	}
	friend Proxy; //to share parameters

	void doForEach(std::function<void(Voxel&)>& operation,
		std::function<bool(Voxel&)>& condition); //iterator - for each voxel
private:
	unsigned int wVox; //dimensions
	unsigned int hVox;
	unsigned int maxW;
	unsigned int maxH;
	SingleCompImage* imIntensity;
	//RealRect* workArea; 
};