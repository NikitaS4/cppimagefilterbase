#pragma once
#include "FragmFiltrator.h"
#include "Voxel.h"
#include <vector>

class FancyThresholdFiltrator : public FragmFiltrator {
public:
	FancyThresholdFiltrator();
	Filter getFilterType() const;	
protected:
	static const Filter f_type = Filter::FANCY_THRESHOLD;
private:
	static void sort(std::vector<double>& vec);
};