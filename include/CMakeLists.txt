set(MATRIXLIB_BRAINCORPS_HEADERS
  matrixlib.h
  )
install(FILES
        ${MATRIXLIB_BRAINCORPS_HEADERS}
        ${PROJECT_BINARY_DIR}/MatrixLibConfig.h
        ${PROJECT_BINARY_DIR}/MatrixLibExport.h
        DESTINATION include)

