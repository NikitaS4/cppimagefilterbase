#include "RectAdapter.h"

RealRect RectAdapter::frectToReal(const FilterRect& frect,
	const image_data& image) {
	RealRect real;

	real.hBeg = image.h / frect.getHBeg();
	real.wBeg = image.w / frect.getWBeg();
	real.hEnd = image.h / frect.getHEnd();
	real.wEnd = image.w / frect.getWEnd();

	return real;
}