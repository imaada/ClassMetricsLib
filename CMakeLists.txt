cmake_minimum_required(VERSION 3.15)
project(ClassMetricsLib)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClassMetricsLib main.cpp Classification/InputVectors/input.cpp Classification/InputVectors/input.hpp Classification/BinaryClassification.cpp Classification/BinaryClassification.h)