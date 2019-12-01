#include "ConvBlurStrategy.h"


void ConvBlurStrategy::fillKernel(ConvKer& kernel) {
	unsigned int norm = kernel.getSize() * kernel.getSize();
	for (unsigned int i = 0; i < kernel.getSize(); ++i) {
		for (unsigned int j = 0; j < kernel.getSize(); ++j) {
			kernel.put(i, j, 1);
		}
	}
	kernel.setNorm(norm);
}