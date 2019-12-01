#include "BlurFiltrator.h"
#include "ImagePixels.h"
#include <vector>

#include "Convolution.h"
#include "ConvBlurStrategy.h"

void BlurFiltrator::apply(RealRect& area, image_data& image) {
	ImagePixels imPxls = ImagePixels::createImage(image);

	std::vector<std::vector<unsigned int>> reds;
	std::vector<std::vector<unsigned int>> greens;
	std::vector<std::vector<unsigned int>> blues;

	auto areaH = area.hEnd - area.hBeg;
	auto areaW = area.wEnd - area.wBeg;

	reds.resize(areaW);
	greens.resize(areaW);
	blues.resize(areaW);		
	
	for (unsigned int curW = area.wBeg, i = 0; curW < area.wEnd; ++curW, ++i) {		
		reds[i].resize(areaH);
		greens[i].resize(areaH);
		blues[i].resize(areaH);		
		for (unsigned int curH = area.hBeg, j = 0; curH < area.hEnd; ++curH, ++j) {			
			auto cortege = imPxls[curW][curH];
			reds[i][j] = cortege.getR();
			greens[i][j] = cortege.getG();
			blues[i][j] = cortege.getB();
		}		
	}	
	
	Convolution conv(kerSize, convStrategy);	
	//conv.printKernel(); //for debug only	
	conv.apply(reds);
	conv.apply(greens);
	conv.apply(blues);	

	for (unsigned int curW = area.wBeg, i = 0; curW < area.wEnd; ++curW, ++i) {
		for (unsigned int curH = area.hBeg, j = 0; curH < area.hEnd; ++curH, ++j) {
			auto cortege = imPxls[curW][curH];
			cortege.setR((unsigned char)reds[i][j]); 
			cortege.setG((unsigned char)greens[i][j]);
			cortege.setB((unsigned char)blues[i][j]);
		}
	}
}

Filter BlurFiltrator::getFilterType() const {
	return f_type;
}