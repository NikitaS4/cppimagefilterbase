#include "ThresholdFiltrator.h"

Filter ThresholdFiltrator::getFilterType() const {
	return f_type;
}

void ThresholdFiltrator::sort(std::vector<double>& vec) {
	//insertion sort
	unsigned int place;
	double buff;
	for (unsigned int head = 1; head < vec.size(); ++head) {		
		for (place = 0; place < vec.size() && place < head &&
			vec[head] > vec[place]; ++place); //find place to insert
		buff = vec[head];
		for (unsigned int i = head; i > place; --i) {
			vec[i] = vec[i - 1];
		}					
		vec[place] = buff;
	}
}

ThresholdFiltrator::ThresholdFiltrator() {
	auto fOp = [](Voxel & voxel)->void {
		std::vector<double> intensities = voxel.get();
		std::vector<double> copyVec = intensities;
		sort(copyVec);
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