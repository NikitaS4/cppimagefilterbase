#include "FancyThresholdFiltrator.h"

#include "Sorts.h"

Filter FancyThresholdFiltrator::getFilterType() const {
	return f_type;
}

FancyThresholdFiltrator::FancyThresholdFiltrator() {
	auto fOp = [](Voxel & voxel)->void {
		std::vector<double> intensities = voxel.get();
		std::vector<double> copyVec = intensities;
		Sorts::sort(copyVec);
		double median = copyVec[copyVec.size() / 2 + copyVec.size() % 2];
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

	wVoxel = 5;
	hVoxel = 5;
	fragmOperation = fOp;
	fragmCondition = fCond;
}