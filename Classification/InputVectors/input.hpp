

#ifndef UNTITLED_INPUT_HPP
#define UNTITLED_INPUT_HPP

#endif

#include "iostream"
#include "vector"

class InputVectors {

public:
    // InputVectors(std::vector<std::vector<int>> ground_truth, std::vector<std::vector<int>> predicted);
//    std::vector<std::vector<int>> compare();
    std::vector<std::vector<int>> getConfustionMatrix();
//    int getInstances();
    std::vector<std::vector<int>> getGroundTruth();
    std::vector<std::vector<int>> getPredicted();
    void setConfusionMatrix(std::vector<std::vector<int>> ground_truth, std::vector<std::vector<int>> predicted);
//    void resizeVector(std::vector<std::vector<int>> vec, int row);
    std::vector<std::vector<int>> matrix;
    std::vector<std::vector<int>> groundTruth;
    std::vector<std::vector<int>> predictedInput;
};