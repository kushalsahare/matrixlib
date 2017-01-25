cmake_minimum_required(VERSION 2.8.9)
project(Matrixlib)
set(CMAKE_BUILD_TYPE Release)


set(MATRIXLIB_VER_MAJOR 0)
set(MATRIXLIB_VER_MINOR 0)
set(MATRIXLIB_VER_PATCH 1)
set(MATRIXLIB_VERSION
    "${MATRIXLIB_VER_MAJOR}.${MATRIXLIB_VER_MINOR}.${MATRIXLIB_VER_PATCH}")
message(STATUS "MATRIXLIB_VERSION == ${MATRIXLIB_VERSION}")

set(INCLUDES ${PROJECT_SOURCE_DIR}/include)
#includes the header
include_directories(${INCLUDES})

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/matrixlib.cpp")

#Generate the static library from the sources
add_library(matrixlib STATIC ${SOURCES})

#Set the location for library installation. Use "sudo make install" to apply
install(TARGETS matrixlib DESTINATION /usr/lib)

enable_testing()

add_subdirectory(tests)

