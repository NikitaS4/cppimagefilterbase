#pragma once
#include "FragmFiltrator.h"
#include "Voxel.h"
#include <vector>

class ThresholdFiltrator : public FragmFiltrator {
public:
	ThresholdFiltrator();
	Filter getFilterType() const;	
protected:
	static const Filter f_type = Filter::THRESHOLD;
private:
	static void sort(std::vector<double>& vec);
};