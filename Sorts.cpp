#include "Sorts.h"
#include <iostream>

void Sorts::sort(std::vector<unsigned int>& vec) {
	//insertion sort
	unsigned int place;
	unsigned int buff;
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