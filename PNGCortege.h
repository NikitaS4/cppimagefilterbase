#pragma once

class PNGCortege {
public:
	PNGCortege(unsigned char* pixel) : rawData(pixel) {}

	unsigned char getR();
	unsigned char getG();
	unsigned char getB();
	unsigned char getA();
	void setR(unsigned char val);
	void setG(unsigned char val);
	void setB(unsigned char val);
	void setA(unsigned char val);
private:
	PNGCortege() = delete;
	unsigned char* rawData;
};