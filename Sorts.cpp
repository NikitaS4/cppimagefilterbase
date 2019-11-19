#include "Sorts.h"
#include <iostream>

void Sorts::sort(std::vector<double>& vec) {
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