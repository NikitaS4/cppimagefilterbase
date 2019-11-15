#include "RedFiltrator.h"

#include "ImagePixels.h"
#include "PNGCortege.h"

void RedFiltrator::apply(RealRect& area, image_data& image) {
	ImagePixels imPxls = ImagePixels::createImage(image);
	for (unsigned int i = area.wBeg; i < area.wEnd; ++i) {
		for (unsigned int j = area.hBeg; j < area.hEnd; ++j) {
			PNGCortege curPixel = imPxls[i][j];
			curPixel.setR((unsigned char)0xFF);
			curPixel.setG((unsigned char)0);
			curPixel.setB((unsigned char)0);
		}
	}
}

Filter RedFiltrator::getFilterType() const {
	return f_type;
}