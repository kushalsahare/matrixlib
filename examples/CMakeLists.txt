cmake_minimum_required(VERSION 2.8.9)
project (Example)
 
#For the shared library:
#set ( PROJECT_LINK_LIBS libtestStudent.so )
#link_directories( ~/exploringBB/extras/cmake/studentlib_shared/build )
 
#For the static library:
set ( PROJECT_LINK_LIBS libmatrixlib.a )
#link_directories( ../build )

link_directories(/usr/lib)
 
include_directories(../include)
include_directories(../src)	

set(EXAMPLES
    matrix_creation
    transpose
    multiplication
    )

foreach(e ${EXAMPLES})
  add_executable(${e} ${e}.cpp)
  target_link_libraries(${e} ${PROJECT_LINK_LIBS})
endforeach()
 
#add_executable(example example.cpp)
#target_link_libraries(example ${PROJECT_LINK_LIBS} )
