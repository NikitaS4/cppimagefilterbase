#pragma once

/*
Constants (convolution kernel sizes)
*/

//#define LAB_MODE

#ifdef LAB_MODE

//default settings to pass the lab

#define BLUR_CONV_KER_SIZE 3
#define EDGE_CONV_KER_SIZE 3
#define FANCY_BLUR_CONV_KER_SIZE 3
#define THRESHOLD_LOCALITY_AREA 5
#define FANCY_THRESHOLD_AREA_H 5
#define FANCY_THRESHOLD_AREA_W 5

#define CONFIG_RECT_IS_INTEGER
#else

//custom settings

#define BLUR_CONV_KER_SIZE 11
#define EDGE_CONV_KER_SIZE 11
#define FANCY_BLUR_CONV_KER_SIZE 5
#define THRESHOLD_LOCALITY_AREA 9
#define FANCY_THRESHOLD_AREA_H 9
#define FANCY_THRESHOLD_AREA_W 9

#endif /* LAB_MODE */

#ifdef CONFIG_RECT_IS_INTEGER
#define CONFIG_RECT_TYPE unsigned int
#else 
#define CONFIG_RECT_TYPE float
#endif /* CONFIG_RECT_IS_INTEGER */