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
	ConvStrategy* edgeStrategy = new ConvEdgeStrategy();
	Convolution conv(kerSize, edgeStrategy);	
	conv.apply(intensityMtx.getMtx());
	intensityMtx.toBWImage(imPxls, area);
}

Filter EdgeFiltrator::getFilterType() const {
	return f_type;
}