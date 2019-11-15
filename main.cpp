#include <iostream>
#include <stdexcept>
#include <exception>

#include "stb_image_write.h"

#include "png_toolkit.h"

#include "ConfigParser.h"
#include "Filter.h"
#include "FilterRect.h"
#include "Filtrator.h"
#include "RedFiltrator.h"
#include "RectAdapter.h"
#include "BlurFiltrator.h"
#include "BWFiltrator.h"
#include "EdgeFiltrator.h"
#include "ThresholdFiltrator.h"
#include "FancyBlurFiltrator.h"

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

		RedFiltrator redFiltrator;
		BlurFiltrator blurFiltrator;
		BWFiltrator bwFiltrator;
		EdgeFiltrator edgeFiltrator;
		ThresholdFiltrator thresholdFiltrator;
		FancyBlurFiltrator fancyBlurFiltrator;

		for (auto &fRect : filterRects) {
			real = RectAdapter::frectToReal(fRect, imageData);
			switch (fRect.getFilter())
			{
			case Filter::RED:
				redFiltrator.apply(real, imageData);
				break;
			case Filter::BLUR:
				blurFiltrator.apply(real, imageData);
				break;
			case Filter::FANCY_BLUR:				
				fancyBlurFiltrator.apply(real, imageData);
				break;
			case Filter::EDGE:
				edgeFiltrator.apply(real, imageData);
				break;
			case Filter::THRESHOLD:
				thresholdFiltrator.apply(real, imageData);
				break;
			case Filter::BW:
				bwFiltrator.apply(real, imageData);
				break;
			default:
				throw std::runtime_error("Bad filter name");
				break;
			}					
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