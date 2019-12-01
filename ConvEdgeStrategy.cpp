#include "ConvEdgeStrategy.h"

void ConvEdgeStrategy::fillKernel(ConvKer& kernel) {
	unsigned int central = kernel.getSize() * kernel.getSize();
	unsigned int center = kernel.getSize() / 2;
	for (unsigned int i = 0; i < kernel.getSize(); ++i) {
		for (unsigned int j = 0; j < kernel.getSize(); ++j) {
			if (i == j && i == (unsigned int)center) {
				kernel.put(i, j, central);
			}
			else {
				kernel.put(i, j, -1);
			}
		}
	}
}