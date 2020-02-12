cmake_minimum_required(VERSION 3.15)
project(ClassMetrics VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)
include_directories(
        Classification/
)
list(APPEND SOURCES
     Classification/InputVectors/input.cpp
)
add_library(${PROJECT_NAME} STATIC ${SOURCES} Classification/BinaryClassification.h Classification/ClassificationFactory.h Classification/MaryClassification.cpp Classification/MaryClassification.h Classification/MultiLabelClassification.cpp Classification/MultiLabelClassification.h Classification/BinaryClassification.cpp)
add_executable(main main.cpp CallMainInMain.h)
target_link_libraries(main ${PROJECT_NAME})