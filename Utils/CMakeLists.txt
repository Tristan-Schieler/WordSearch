cmake_minimum_required(VERSION 3.23.2)

project(Utils)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(
    "./incl"
)

set(Headers
    "incl/FileReader.h"
)
set(Sources
    "src/FileReader.cpp"
)

add_library(Utils STATIC ${Headers} ${Sources})