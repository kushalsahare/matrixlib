include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
set(MATRIXLIB_BRAINCORPS_SRCS
    matrixlib.cpp    
 )
set(MATRIXLIB_BRAINCORPS_HDRS
    ${PROJECT_SOURCE_DIR}/include/matrixlib.h
    )

add_library(matrixlib_braincorps_static STATIC ${MATRIXLIB_BRAINCORPS_SRCS} ${MATRIXLIB_BRAINCORPS_SRCS_HDRS})
add_library(matrixlib_braincorps_shared SHARED ${MATRIXLIB_BRAINCORPS_SRCS} ${MATRIXLIB_BRAINCORPS_SRCS_HDRS})
generate_export_header(matrixlib_braincorps_shared
    EXPORT_FILE_NAME ${PROJECT_BINARY_DIR}/MatrixLibExport.h
    BASE_NAME matrixlib_braincorps
    EXPORT_MACRO_NAME MATRIXLIB_BRAINCORPS_API
    )
set_target_properties(matrixlib_braincorps_static PROPERTIES
	OUTPUT_NAME matrixlib_braincorps
	COMPILE_FLAGS -DMATRIXLIB_BRAINCORPS_STATIC_DEFINE
	)

install(TARGETS matrixlib_braincorps_static matrixlib_braincorps_shared DESTINATION lib)
install(FILES ${PROJECT_BINARY_DIR}/MatrixLibExport.h DESTINATION include)

