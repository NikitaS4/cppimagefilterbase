#include <iostream>

#include "stb_image_write.h"

#include "png_toolkit.h"

#include "ConfigParser.h"
#include "Filter.h"
#include "FilterRect.h"
#include "Filtrator.h"
#include "RedFiltrator.h"
#include "RectAdapter.h"


//old code
//int x;
//int y;
//int channels;
//
//unsigned char *data = stbi_load(argv[1], &x, &y, &channels, 0);
//
//for (int i = channels * x * y / 2; i < channels * x * y; i++/* += channels*/)
//{
//	if (i % channels == 0)
//		data[i] = 0xFF;
//	else 
//		data[i] = 0x00;
//}
//
////std::cout << "Channels: " << channels << std::endl;
//
//if (!stbi_write_png(argv[2], x, y, channels, data, 0))
//{
//	std::cout << "Error!!" << std::endl;
//}		


int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test images!
    try
    {
        if (argc != 4)
            throw "Not enough arguments";

        png_toolkit studTool;

		RedFiltrator redFiltrator;

        studTool.load(argv[2]);      

		ConfigParser parser;
		parser.init(argv[1]);
		std::vector<FilterRect> filterRects = parser.getRects();
		RealRect real;

		image_data imageData = studTool.getPixelData();

		for (auto &fRect : filterRects) {
			real = RectAdapter::frectToReal(fRect, imageData);
			redFiltrator.apply(real, imageData);
		}

		studTool.setPixelData(imageData);
		studTool.save(argv[3]);
    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
