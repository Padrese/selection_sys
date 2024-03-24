## Required version
cmake_minimum_required (VERSION 3.21.3)

## Project name
project(GaleShapley CXX)

## Compiler
set(CMAKE_CPP_COMPILER g++)

## Standard
set(CMAKE_CXX_STANDARD 17)

## Project compilation options
## -pg : profiling
## -Wall : warnings
## -Wextra: warnings not shown by -Wall
## -lgtest: get gtest library (but expect us to deal with the main)
set(CMAKE_CXX_FLAGS "-Iinclude")
set(CMAKE_CXX_FLAGS "-pg")
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS "-Wextra")
set(CMAKE_CXX_FLAGS "-lgtest")

##Profiling during link time
set(CMAKE_EXE_LINKER_FLAGS "-pg")

#Find gtest packages
find_package(GTest REQUIRED)

## Load GoogleTest
include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG main
)

set(gtest_force_shared_crt ON CACHE BOOL ”” FORCE)
FetchContent_MakeAvailable(googletest)

#Doxygen doc
find_package(Doxygen)

#Input et output linked to Doxygen
set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/doc/Doxyfile)
set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

#Config
configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

#Parametrize make doc command
add_custom_target(doc
	COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	)

## Define localization headers.
include_directories(${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)

add_subdirectory(test)

add_subdirectory(demo)

