#include "PNGCortege.h"

char PNGCortege::getR()
{
	return rawData[0];
}

char PNGCortege::getG()
{
	return rawData[1];
}

char PNGCortege::getB()
{
	return rawData[2];
}

char PNGCortege::getA()
{
	return rawData[3];
}

void PNGCortege::setR(char val)
{
	rawData[0] = val;
}

void PNGCortege::setG(char val)
{
	rawData[1] = val;
}

void PNGCortege::setB(char val)
{
	rawData[2] = val;
}

void PNGCortege::setA(char val)
{
	rawData[3] = val;
}