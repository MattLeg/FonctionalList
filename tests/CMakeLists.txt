cmake_minimum_required(VERSION 3.17)
project(FListTest)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} src)

add_executable(FListTestRun FListTest.cpp)

target_link_libraries(FListTestRun FListLib)
target_link_libraries(FListTestRun gtest gtest_main)
target_link_libraries(FListTestRun spdlog)

add_test( FListTestRun FListTestRun )

include_directories(src)
