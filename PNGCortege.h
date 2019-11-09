#pragma once

class PNGCortege {
public:
	PNGCortege(unsigned char* pixel) : rawData(pixel) {}

	char getR();
	char getG();
	char getB();
	char getA();
	void setR(char val);
	void setG(char val);
	void setB(char val);
	void setA(char val);
private:
	PNGCortege() = delete;
	unsigned char* rawData;
};