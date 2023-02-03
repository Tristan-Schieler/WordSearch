cmake_minimum_required(VERSION 3.23.2)

project(WordBoard)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(
    "./incl"
)

set(Headers
    "incl/wordBoard.h"
)
set(Sources
    "src/wordBoard.cpp"
)

add_library(WordBoard STATIC ${Headers} ${Sources})