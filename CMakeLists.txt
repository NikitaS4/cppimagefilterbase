cmake_minimum_required(VERSION 2.8)

project(student_toolkit)
add_executable(${PROJECT_NAME} "png_toolkit.cpp" "png_toolkit.h"
    "stb_image.h" "stb_image_write.h" "ConfigParser.h" "ConfigParser.cpp" "Filter.h" "Filter.cpp" "FilterRect.h" "FilterRect.cpp" "Filtrator.h" "RectAdapter.h" "RectAdapter.cpp" "RedFiltrator.h" "RedFiltrator.cpp" "RealRect.h" "main.cpp")
