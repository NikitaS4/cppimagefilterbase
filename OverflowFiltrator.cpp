#include "OverflowFiltrator.h"

#include "ImagePixels.h"
#include "PNGCortege.h"

void OverflowFiltrator::apply(RealRect& area, image_data& image) {
	ImagePixels imPxls = ImagePixels::createImage(image);
	for (unsigned int i = area.wBeg; i < area.wEnd; ++i) {
		for (unsigned int j = area.hBeg; j < area.hEnd; ++j) {
			PNGCortege curPixel = imPxls[i][j];			
			curPixel.setB((unsigned char)0xFF);
		}
	}
}

Filter OverflowFiltrator::getFilterType() const {
	return f_type;
}