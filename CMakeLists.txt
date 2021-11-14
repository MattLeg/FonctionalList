cmake_minimum_required(VERSION 3.17)
project(functionalListCPP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_executable(functionalListCPP main.cpp)
target_link_libraries(functionalListCPP FListLib)

include_directories(src)
add_subdirectory(src)

add_subdirectory(spdlog)
add_subdirectory(Google_tests)
add_subdirectory(tests)