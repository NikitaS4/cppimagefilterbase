#pragma once

#include <vector>
#include <iostream>

class ConvKer {
public:
	ConvKer(unsigned int dim);
	void put(unsigned int i, unsigned int j, int data);
	void setNorm(unsigned int divisor);
	unsigned int getSize();
	unsigned int apply(std::vector<std::vector<unsigned int>>& imagePart);	
	void print(); //for debug only
private:
	ConvKer() = delete;
	unsigned int clamp(int intensity);
	unsigned int size;
	unsigned int normalizationDivisor = 1;
	std::vector<std::vector<int>> kernel;	
};