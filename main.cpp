#include <iostream>
#include <stdexcept>
#include <exception>

#include "stb_image_write.h"

#include "png_toolkit.h"

#include "ConfigParser.h"
#include "Filter.h"
#include "FilterRect.h"
#include "Filtrator.h"
#include "FilterBase.h"
#include "RealRect.h"
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

        studTool.load(argv[2]);   

		ConfigParser parser;
		parser.initStream(argv[1]);
		std::vector<FilterRect> filterRects = parser.getRects();
		RealRect real;

		image_data imageData = studTool.getPixelData();
		FilterBase filterBase;

		for (auto &fRect : filterRects) {
			real = RectAdapter::frectToReal(fRect, imageData);
			filterBase.launchFilter(fRect.getFilter(), real, imageData);
		}		
		studTool.save(argv[3]);
    }
    catch (std::runtime_error& err)
    {
        std::cout << "Error: " << err.what() << std::endl;        
    }			
	catch (std::exception& err) {
		std::cout << "Exception: " << err.what() << "\n";
	}
	catch (...) {
		std::cout << "Unknown exception\n";
	}

	//std::cout << "Done!\n";
    return 0;
}