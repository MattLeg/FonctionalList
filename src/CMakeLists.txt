cmake_minimum_required(VERSION 3.17)

set(HEADER_FILES include/FList.h include/FList.tpp)
set(SOURCE_FILES FList.cpp)

add_library(FListLib STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(FListLib spdlog)
