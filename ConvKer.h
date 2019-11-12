#pragma once

#include <vector>
#include <iostream>

class ConvKer {
public:
	ConvKer(unsigned int dim);
	void put(unsigned int i, unsigned int j, double data);
	unsigned int getSize();
	double apply(std::vector<std::vector<double>>& imagePart);
	double sumApply(std::vector<std::vector<double>>& imagePart);
	void print(); //for debug only
private:
	ConvKer() = delete;
	unsigned int size;
	std::vector<std::vector<double>> kernel;
};