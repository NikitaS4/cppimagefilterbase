#include "FragmFiltrator.h"
#include "Fragmentation.h"
#include "SingleCompImage.h"
#include "ImagePixels.h"

void FragmFiltrator::apply(RealRect& area, 
	image_data& image) {
	ImagePixels imPxls = ImagePixels::createImage(image);
	SingleCompImage intensity(imPxls, area);
	Fragmentation fragmentation(wVoxel, hVoxel, intensity);
	fragmentation.doForEach(fragmOperation, fragmCondition);
	intensity.toBWImage(imPxls, area);
}