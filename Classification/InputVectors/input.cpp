#include "input.hpp"
#include "iostream"

void InputVectors::setConfusionMatrix(std::vector<std::vector<int>> ground_truth, std::vector<std::vector<int>> predicted){

    int n = ground_truth[0].size();
    std::vector <std::vector<int>> confusionMatrix;
    if ( ground_truth[0].size() == 1){
       confusionMatrix.resize(2, std::vector<int>(2));
    }
    else{
        confusionMatrix.resize(n, std::vector<int>(n));

    }

    for (int i=0; i < ground_truth.size();i++) {
        for (int j=0; j < ground_truth[0].size();j++) {

//            std::cout<< confusionMatrix.size() << std::endl;
//            std::cout<< confusionMatrix[0].size() << std::endl;


            if ( ground_truth[0].size() == 1){
                //TP
                if (ground_truth[i][j] == 1 && predicted[i][j] == 1) {
                    confusionMatrix[0][0] += 1;
                }
                    //FP
                else if (ground_truth[i][j] == 1 && predicted[i][j] == 0) {
                    confusionMatrix[0][1] += 1;
                }
                    //FN
                else if (ground_truth[i][j] == 0 && predicted[i][j] == 1) {
                    confusionMatrix[1][0] += 1;
                }
                    //TN
                else if (ground_truth[i][j] == 0 && predicted[i][j] == 0) {
                    confusionMatrix[1][1] += 1;
                }
            }

            else if (ground_truth[0].size()>1){
                if (ground_truth[i][j] == 1 && predicted[i][j] == 1) {
                    confusionMatrix[j][j] += 1;
                }
                else if (ground_truth[i][j] == 1 && predicted[i][j] != 1){
                    for (int g = 0; g < ground_truth[0].size(); g++){
                        if(ground_truth[i][j] == predicted[i][g]){
                            confusionMatrix[g][j] += 1;
                            break;
                        }
                    }
                }

                }
            }

        }

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

//int InputVectors::getInstances(){
//    int num = matrix[0][0] + matrix[1][1] + matrix[0][1] + matrix[1][0];
//    return num;
//}



//std::vector<std::vector<int>> InputVectors::compare(){
//
//    std::vector<std::vector<int>> a =  {{1,2}, {3,4}};
//    return a;
//}
