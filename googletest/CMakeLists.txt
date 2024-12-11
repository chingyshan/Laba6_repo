project(Google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_executable(Test_1 ../Task1/Test1.cpp ../Task1/functions.cpp)
target_link_libraries(Test_1 gtest gtest_main)
add_executable(Test_2 ../Task2/Test2.cpp ../Task2/functions.cpp)
target_link_libraries(Test_2 gtest gtest_main)
add_executable(Test_3 ../Task3/Test3.cpp ../Task3/functions.cpp)
target_link_libraries(Test_3 gtest gtest_main)

