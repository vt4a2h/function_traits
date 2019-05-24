cmake_minimum_required(VERSION 3.0)

set(FT_INCLUDE ${CMAKE_SOURCE_DIR}/../src)

include_directories(${FT_INCLUDE})

project(test)
add_executable(${PROJECT_NAME} "main.cpp" ${FT_INCLUDE})

set_property(TARGET test PROPERTY CXX_STANDARD 17)
set_property(TARGET test PROPERTY CXX_EXTENSIONS OFF)
