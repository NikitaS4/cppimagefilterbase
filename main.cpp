#include <iostream>

#include "stb_image_write.h"

#include "png_toolkit.h"

int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test images!
    try
    {
        if (argc != 3)
            throw "Not enough arguments";

        //png_toolkit studTool;
        //studTool.load(argv[1]);
        //studTool.save(argv[2]);

		int x;
		int y;
		int channels;

		unsigned char *data = stbi_load(argv[1], &x, &y, &channels, 0);

		for (int i = 0; i < channels * x * y / 2; i++/* += channels*/)
		{
			if (i % channels == 0)
				data[i] = 0xFF;
			else 
				data[i] = 0x00;
		}

		//std::cout << "Channels: " << channels << std::endl;

		if (!stbi_write_png(argv[2], x, y, channels, data, 0))
		{
			std::cout << "Error!!" << std::endl;
		}		
    }
    catch (const char *str)
    {
        std::cout << "Error: " << str << std::endl;
        return 1;
    }

    return 0;
}
