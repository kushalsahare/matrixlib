cmake_minimum_required(VERSION 2.6.2)
project(MATRIXLIB)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
enable_testing()
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${PROJECT_SOURCE_DIR}/cmake")
include(CheckCXXCompilerFlag)
include(GenerateExportHeader)
set(MATRIXLIB_VER_MAJOR 0)
set(MATRIXLIB_VER_MINOR 0)
set(MATRIXLIB_VER_PATCH 1)
set(MATRIXLIB_VERSION
    "${MATRIXLIB_VER_MAJOR}.${MATRIXLIB_VER_MINOR}.${MATRIXLIB_VER_PATCH}")
message(STATUS "MATRIXLIB_VERSION == ${MATRIXLIB__VERSION}")

option(MATRIXLIB_BUILD_TESTS "Whether to build tests" OFF)
option(MATRIXLIB_BUILD_DOCS "Whether to build documentation" ON)
option(MATRIXLIB_ENABLE_COVERAGE "Instrument tests for coverage" OFF)


if(MATRIXLIB_BUILD_DOCS)
  find_package(Doxygen)
  if(DOXYGEN_FOUND)
  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/doxyfile @ONLY)
  file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/doc")
  add_custom_target(doc
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/doxyfile
    WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/doc"
    COMMENT "Generating API documentation with Doxygen" VERBATIM
  )
  else()
    message(STATUS "Doxygen not found -- not building docs")
  endif()
endif()


if(CMAKE_COMPILER_IS_GNUCC OR "${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} - -Wall")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  add_definitions(-D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_BINARY_DIR}
    ${PROJECT_BINARY_DIR}/src
    )
add_subdirectory(src)
#add_subdirectory(examples)
add_subdirectory(include)
if(MATRIXLIB_BUILD_TESTS)
  add_subdirectory(gtest-1.7.0)
  include_directories(${gtest_SOURCE_DIR}/include)
  add_subdirectory(tests)
endif()

configure_file(MatrixLibConfig.h.in MatrixLibConfig.h)

