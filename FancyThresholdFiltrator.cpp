#include "FancyThresholdFiltrator.h"
#include "Settings.h"
#include "Sorts.h"

Filter FancyThresholdFiltrator::getFilterType() const {
	return f_type;
}

FancyThresholdFiltrator::FancyThresholdFiltrator() {
	auto fOp = [](Voxel & voxel)->void {
		std::vector<unsigned int> intensities = voxel.get();
		std::vector<unsigned int> copyVec = intensities;
		Sorts::sort(copyVec);
		unsigned int median = copyVec[copyVec.size() / 2 + copyVec.size() % 2];
		unsigned int nulledPix = 0;

		for (unsigned int i = 0; i < intensities.size(); ++i) {
			if (intensities[i] < median) {
				intensities[i] = 0;
				++nulledPix;
			}
		}

		//the cycle below adds noize to the smooth area
		for (unsigned int i = 0; i < intensities.size() &&
			nulledPix < intensities.size() / 2 + 1; ++nulledPix, ++i) {
			if (intensities[i] == median) {
				intensities[i] = 0;
			}
		}
		voxel.put(intensities);
	};	

	auto fCond = [](Voxel & voxel)->bool {
		return true;
	};

	wVoxel = FANCY_THRESHOLD_AREA_W;
	hVoxel = FANCY_THRESHOLD_AREA_H;
	fragmOperation = fOp;
	fragmCondition = fCond;
}