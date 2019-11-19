# My cppimagefilterbase
Image filters

Available filters:

Red			# Set pixels to red

Blur		# Blur image

BW 			# Black-white

Edge		# Highlights edges on the image

FancyThreshold	# Noizes smooth areas, based on fragmentations

Threshold	# Like edge but non-convolutional

FancyBlur	# Just for fun, it's blur filter with bug (wrong kernel)

Overflow	# Sets blue component of each pixel to maximum

How to use:
1. Put image (*.png or *.jpg) nearby *.exe file
2. Write configuration file
3. Launch *.exe with 3 arguments: configuration file, image, output image name

Config grammar:
Each line consists of the name of the filter (see Available filters) and filter application area (rectangle)
The rectangle is set with 4 numbers - if You divide width and height by them, You will receive screen coordinates of the rectangle
Coordinates order - top left bottom right (to divide by them: width height width height)
If the number is 0, it means 0 coordinate

Config example:

Red 0 0 2 2

Blur 2 2 1 1

In the folder example You can find another config file example
