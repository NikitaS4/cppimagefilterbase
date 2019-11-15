#include "PNGCortege.h"

unsigned char PNGCortege::getR()
{
	return rawData[0];
}

unsigned char PNGCortege::getG()
{
	return rawData[1];
}

unsigned char PNGCortege::getB()
{
	return rawData[2];
}

unsigned char PNGCortege::getA()
{
	return rawData[3];
}

void PNGCortege::setR(unsigned char val)
{
	rawData[0] = val;
}

void PNGCortege::setG(unsigned char val)
{
	rawData[1] = val;
}

void PNGCortege::setB(unsigned char val)
{
	rawData[2] = val;
}

void PNGCortege::setA(unsigned char val)
{
	rawData[3] = val;
}