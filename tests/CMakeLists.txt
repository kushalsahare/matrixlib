
find_package(GTest REQUIRED)
set(TESTS
    test1
    test2  
)

set(PROJECT_TEST_NAME "${PROJECT_NAME_STR}_test")
include_directories(${GTEST_INCLUDE_DIRS} ${INCLUDES})

foreach(t ${TESTS})
add_executable(${t} ${t}.cpp)
target_link_libraries(${t} ${PROJECT_NAME_STR} ${GTEST_BOTH_LIBRARIES} pthread)
add_test(${t} ${t})
endforeach()
