include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
set(MATRIXLIB_SRCS
    matrixlib.cpp    
 )
set(MATRIXLIB_HDRS
    ${PROJECT_SOURCE_DIR}/include/matrixlib.h
    )

add_library(matrixlib_static STATIC ${MATRIXLIB_SRCS} ${MATRIXLIB_HDRS})
add_library(matrixlib_shared SHARED ${MATRIXLIB_SRCS} ${MATRIXLIB_SRCS_HDRS})
generate_export_header(matrixlib_shared
    EXPORT_FILE_NAME ${PROJECT_BINARY_DIR}/MatrixLibExport.h
    BASE_NAME matrixlib
    EXPORT_MACRO_NAME MATRIXLIB_API
    )
set_target_properties(matrixlib_static PROPERTIES
	OUTPUT_NAME matrixlib
	COMPILE_FLAGS -DMATRIXLIB_STATIC_DEFINE
	)

install(TARGETS matrixlib_static matrixlib_shared DESTINATION lib)
install(FILES ${PROJECT_BINARY_DIR}/MatrixLibExport.h DESTINATION include)

