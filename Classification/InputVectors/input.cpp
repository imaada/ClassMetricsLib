#include "input.hpp"

InputVectors::InputVectors(std::vector<std::vector<int>> ground_truth, std::vector<std::vector<int>> predicted){
    std::cout << "this is a class" << std::endl;
    int n = ground_truth.size();

    std::vector <std::vector<int>> confusionMatrix(2, std::vector<int>(n, 0));

    for (int i=0; i < ground_truth[0].size();i++) {
        //TP
        if (ground_truth[0][i] == 1 && predicted[0][i] == 1){
            confusionMatrix[0][0] +=1;
        }
        //FP
        else if (ground_truth[0][i] == 1 && predicted[0][i]==0){
            confusionMatrix[0][1] +=1;
        }
        //FN
        else if (ground_truth[0][i] == 0 && predicted[0][i]== 1){
            confusionMatrix[1][0] +=1;
        }
        //TN
        else if (ground_truth[0][i] == 0 && predicted[0][i]== 0){
            confusionMatrix[1][1] +=1;
        }

    };

    //matrix format for binary
    /*  
            TP  FP
            FN  TN
    */
     
    matrix = confusionMatrix;

}

std::vector<std::vector<int>> InputVectors::getConfustionMatrix(){
    return matrix;
}

int InputVectors::getInstances(){
    int num = matrix[0][0] + matrix[1][1] + matrix[0][1] + matrix[1][0];
    return num;
}



std::vector<std::vector<int>> InputVectors::compare(){

    std::vector<std::vector<int>> a =  {{1,2}, {3,4}};
    return a;
}