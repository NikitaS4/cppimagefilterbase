#include "FilterBase.h"

#include "RedFiltrator.h"
#include "RectAdapter.h"
#include "BlurFiltrator.h"
#include "BWFiltrator.h"
#include "EdgeFiltrator.h"
#include "FancyThresholdFiltrator.h"
#include "FancyBlurFiltrator.h"
#include "OverflowFiltrator.h"
#include "ThresholdFiltrator.h"
#include <iostream>
#include <map>

FilterBase::FilterBase() {		
	filterMap.insert(std::make_pair(Filter::RED, new RedFiltrator()));
	filterMap.insert(std::make_pair(Filter::BLUR, new BlurFiltrator()));
	filterMap.insert(std::make_pair(Filter::BW, new BWFiltrator()));
	filterMap.insert(std::make_pair(Filter::EDGE, new EdgeFiltrator()));
	filterMap.insert(std::make_pair(Filter::THRESHOLD, new ThresholdFiltrator()));
	filterMap.insert(std::make_pair(Filter::FANCY_THRESHOLD, new FancyThresholdFiltrator()));
	filterMap.insert(std::make_pair(Filter::FANCY_BLUR, new FancyBlurFiltrator()));
	filterMap.insert(std::make_pair(Filter::OVER, new OverflowFiltrator()));
	if (filterMap.size() != (unsigned int)(Filter::SIZE) - 1)
		throw std::runtime_error("Not all filters added into the filter base");
}

FilterBase::~FilterBase() {
	for (unsigned int i = (unsigned int)(Filter::UNDEFINED) + 1; 
		i < (unsigned int)(Filter::SIZE); ++i) {
		delete filterMap[(Filter)i];
	}
}

void FilterBase::launchFilter(Filter filter, RealRect& real, image_data& imageData) {
	filterMap[filter]->apply(real, imageData);
}