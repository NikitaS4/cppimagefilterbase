#pragma once
#include "Filtrator.h"
#include <functional>
#include "Voxel.h"

class FragmFiltrator : public Filtrator {
public:
	void apply(RealRect& area, image_data& image);
	virtual Filter getFilterType() const = 0;
protected:
	std::function<void(Voxel&)> fragmOperation;
	std::function<bool(Voxel&)> fragmCondition;
	unsigned int wVoxel;
	unsigned int hVoxel;	
	static const Filter f_type = Filter::UNDEFINED;
};