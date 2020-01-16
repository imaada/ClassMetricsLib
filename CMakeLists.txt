cmake_minimum_required(VERSION 3.15)
project(ClassMetrics VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
include_directories(
        Classification/InputVectors
)
list(APPEND SOURCES
     Classification/InputVectors/input.cpp
)
add_library(${PROJECT_NAME} STATIC ${SOURCES})
add_executable(main main.cpp)
target_link_libraries(main ${PROJECT_NAME})