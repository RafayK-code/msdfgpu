cmake_minimum_required(VERSION 3.15)
project("msdfgpu")

option(MSDFGPU_FREETYPE_DIR "Location of Freetype installation" "")

option(MSDFGPU_ENABLE_OPENGL "Enable OpenGL Backend" ON)
option(MSDFGPU_USE_GLAD "Use GLAD for OpenGL Loading" OFF)
option(MSDFGPU_USE_GLEW "Use GLEW for OpenGL Loading" OFF)

option(MSDFGPU_ENABLE_VULKAN "Enable Vulkan Backend" OFF)

option(MSDFGPU_BUILD_STATIC "Build as a Shared Library" ON)
option(MSDFGPU_BUILD_SHARED "Build as a Shared Library" OFF)

find_package(Freetype REQUIRED)

if (NOT Freetype_FOUND AND MSDFGPU_FREETYPE_DIR)
    find_path(FREETYPE_INCLUDE_DIR freetype/ft2build.h PATHS ${MSDFGPU_FREETYPE_DIR}/include)
    find_library(FREETYPE_LIBRARY NAMES freetype freetype.dll freetype.lib PATHS ${MSDFGPU_FREETYPE_DIR}/lib)
    if (FREETYPE_INCLUDE_DIR AND FREETYPE_LIBRARY)
        message(STATUS "Found FreeType in ${FREETYPE_DIR}")
        set(Freetype_FOUND TRUE)
    endif()
endif()

if (NOT Freetype_FOUND)
    message(FATAL_ERROR "Could not find FreeType. Please specify the location.")
endif()

set(SOURCES
    src/msdfgpu.cpp
)

if (MSDFGPU_ENABLE_OPENGL)
endif()

if (MSDFGPU_BUILD_SHARED)
    add_library(msdfgpu SHARED ${SOURCES})
else()
    add_library(msdfgpu STATIC ${SOURCES})
endif()