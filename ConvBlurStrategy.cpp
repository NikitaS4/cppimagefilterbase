#include "ConvBlurStrategy.h"


void ConvBlurStrategy::fillKernel(ConvKer& kernel) {
	double mean = 1 / ((double)kernel.getSize() * kernel.getSize());
	for (unsigned int i = 0; i < kernel.getSize(); ++i) {
		for (unsigned int j = 0; j < kernel.getSize(); ++j) {
			kernel.put(i, j, mean);
		}
	}
}