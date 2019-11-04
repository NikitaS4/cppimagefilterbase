#include "RectAdapter.h"
#include "FilterRect.h"

RealRect RectAdapter::frectToReal(const FilterRect& frect,
	const image_data& image) {
	RealRect real;	

	if (frect.getHBeg() == 0)
		real.hBeg = 0;
	else
		real.hBeg = image.h / frect.getHBeg();

	if (frect.getWBeg() == 0)
		real.wBeg = 0;
	else
		real.wBeg = image.w / frect.getWBeg();

	if (frect.getHEnd() == 0)
		real.hEnd = 0;
	else
		real.hEnd = image.h / frect.getHEnd();

	if (frect.getWEnd() == 0)
		real.wEnd = 0;
	else 
		real.wEnd = image.w / frect.getWEnd();

	return real;
}