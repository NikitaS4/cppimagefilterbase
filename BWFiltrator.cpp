#include "BWFiltrator.h"
#include "ImagePixels.h"

Filter BWFiltrator::getFilterType() const {
	return f_type;
}

double BWFiltrator::compress(const double red, const double green, const double blue) {
	static const double factors[3] = { 0.3, 0.6, 0.1 };
	return factors[0] * red + factors[1] * green + factors[2] * blue;
}

void BWFiltrator::apply(RealRect& area, image_data& image) {
	ImagePixels imPxls = ImagePixels::createImage(image);
	unsigned char intensity;
	for (unsigned int i = area.wBeg; i < area.wEnd; ++i) {
		for (unsigned int j = area.hBeg; j < area.hEnd; ++j) {
			PNGCortege curPixel = imPxls[i][j];
			intensity = (unsigned char)compress(curPixel.getR(), curPixel.getG(),
				curPixel.getB());
			curPixel.setR((unsigned char)intensity);
			curPixel.setG((unsigned char)intensity);
			curPixel.setB((unsigned char)intensity);
		}
	}
}