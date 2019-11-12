#include "EdgeFiltrator.h"
#include "ImagePixels.h"
#include "SingleCompImage.h"
#include "BWFiltrator.h"
#include "Convolution.h"
#include "ConvEdgeStrategy.h"

void EdgeFiltrator::apply(RealRect& area,
	image_data& image) {	
	ImagePixels imPxls = ImagePixels::createImage(image);
	SingleCompImage intensityMtx(imPxls, area);	

	unsigned int i;
	unsigned int j;
	for (unsigned int curW = area.wBeg, i = 0; curW < area.wEnd; ++curW, ++i) {
		for (unsigned int curH = area.hBeg, j = 0; curH < area.hEnd; ++curH, ++j) {
			auto cortege = imPxls[curW][curH];
		}
	}
	ConvStrategy* edgeStrategy = new ConvEdgeStrategy();
	Convolution conv(kerSize, edgeStrategy);	
	conv.apply(intensityMtx.getMtx());
	intensityMtx.toBWImage(imPxls, area);
}

Filter EdgeFiltrator::getFilterType() const {
	return f_type;
}