#include "RedFiltrator.h"

void RedFiltrator::apply(const RealRect& area, image_data& image) {
	unsigned char* curBytes = nullptr;
	for (unsigned int i = area.hBeg; i < area.hEnd; ++i) {
		for (unsigned int j = area.wBeg; j < area.wEnd; ++j) {
			curBytes = &(image.pixels[(i * image.w + j) * image.compPerPixel]);
			curBytes[0] = (unsigned char)0xFF;
			curBytes[1] = 0;
			curBytes[2] = 0;
		}
	}
}

Filter RedFiltrator::getFilterType() const {
	return f_type;
}