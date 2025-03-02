cmake_minimum_required(VERSION 3.15)
project("msdfgpu")

option(MSDFGPU_FREETYPE_DIR "Location of Freetype installation" "")

find_package(Freetype REQUIRED)

if (NOT Freetype_FOUND AND MSDFGPU_FREETYPE_DIR)
    find_path(FREETYPE_INCLUDE_DIR freetype/ft2build.h PATHS ${MSDFGPU_FREETYPE_DIR}/include)
endif()