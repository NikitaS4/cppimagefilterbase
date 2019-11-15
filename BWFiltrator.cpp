#include "BWFiltrator.h"
#include "ImagePixels.h"
#include "SingleCompImage.h"

Filter BWFiltrator::getFilterType() const {
	return f_type;
}

void BWFiltrator::apply(RealRect& area, image_data& image) {
	ImagePixels imPxls = ImagePixels::createImage(image);
	SingleCompImage intensityMtx(imPxls, area);		
	intensityMtx.toBWImage(imPxls, area);
}