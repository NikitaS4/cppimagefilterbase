#include "ThresholdFiltrator.h"
#include "NeighborGetter.h"
#include "ImagePixels.h"
#include "Sorts.h"

Filter ThresholdFiltrator::getFilterType() const {
	return f_type;
}

void ThresholdFiltrator::apply(RealRect& area, image_data& image) {
	ImagePixels imPxls = ImagePixels::createImage(image);
	SingleCompImage intensityMtx(imPxls, area);
	NeighborGetter neighborGetter(intensityMtx, localityArea);

	SingleCompImage newMtx(intensityMtx);

	unsigned int wLim = intensityMtx.getW();
	unsigned int hLim = intensityMtx.getH();

	for (unsigned int curW = 0; curW < wLim; ++curW) {
		for (unsigned int curH = 0; curH < hLim; ++curH) {
			std::vector<unsigned int> locality = neighborGetter.get(curW, curH);
			Sorts::sort(locality);
			unsigned int locSize = locality.size();				
			unsigned int median = locality[locSize / 2];
			if (intensityMtx[curW][curH] < median) {
				newMtx[curW][curH] = 0;
			}			
		}
	}

	std::swap(intensityMtx, newMtx);

	intensityMtx.toBWImage(imPxls, area);
}