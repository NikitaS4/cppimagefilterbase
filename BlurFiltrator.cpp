#include "BlurFiltrator.h"
#include "ImagePixels.h"
#include <vector>
#include <iostream>

#include "Convolution.h"
#include "ConvBlurStrategy.h"

void BlurFiltrator::apply(RealRect& area, image_data& image) {
	ImagePixels imPxls = ImagePixels::createImage(image);

	std::vector<std::vector<double>> reds;
	std::vector<std::vector<double>> greens;
	std::vector<std::vector<double>> blues;

	auto areaH = area.hEnd - area.hBeg;
	auto areaW = area.wEnd - area.wBeg;

	reds.resize(areaW);
	greens.resize(areaW);
	blues.resize(areaW);		

	for (unsigned int i = area.wBeg; i < area.wEnd; ++i) {		
		reds[i - area.wBeg].resize(areaH);
		greens[i - area.wBeg].resize(areaH);
		blues[i - area.wBeg].resize(areaH);		
		for (unsigned int j = area.hBeg; j < area.hEnd; ++j) {			
			auto cortege = imPxls[i][j];
			reds[i - area.wBeg][j - area.hBeg] = cortege.getR();
			greens[i - area.wBeg][j - area.hBeg] = cortege.getG();
			blues[i - area.wBeg][j - area.hBeg] = cortege.getB();
		}		
	}	

	ConvStrategy* blurStrategy = 
		new ConvBlurStrategy();	
	Convolution conv(kerSize, blurStrategy);	
	conv.apply(reds);
	conv.apply(greens);
	conv.apply(blues);	

	for (unsigned int i = area.wBeg; i < area.wEnd; ++i) {		
		for (unsigned int j = area.hBeg; j < area.hEnd; ++j) {
			auto cortege = imPxls[i][j];
			cortege.setR((unsigned char)reds[i - area.wBeg][j - area.hBeg]); 
			cortege.setG((unsigned char)greens[i - area.wBeg][j - area.hBeg]);
			cortege.setB((unsigned char)blues[i - area.wBeg][j - area.hBeg]);
		}
	}
}

Filter BlurFiltrator::getFilterType() const {
	return f_type;
}