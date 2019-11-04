#include <iostream>

#include "stb_image_write.h"

#include "png_toolkit.h"

#include "ConfigParser.h"
#include "Filter.h"
#include "FilterRect.h"
#include "Filtrator.h"
#include "RedFiltrator.h"
#include "RectAdapter.h"	


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
