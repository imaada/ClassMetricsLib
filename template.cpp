#include "template.hpp"


Classification ClassificationFatory::createClassification(ClassificationType type){
    switch(type){
        case BINARY:{   
            BinaryClassification b;
            return b;
        }

        default: {
            Classification a;
            return a;
        }

    }
}


float BinaryClassification::accuray(){
    return 1.0;
}


InputVectors::InputVectors(std::vector<std::vector<int>> ground_truth, std::vector<std::vector<int>> predicted){
    std::cout << "this is a class" << std::endl;
    int n = ground_truth.size();
    std::vector <std::vector<int>> confusionmatrix(2,n);
    for (int i=0; i < ground_truth[0].size();i++) {
        if (ground_truth[0][i] == 1 && predicted[0][i] == 1){
            confusionmatrix[1][1] +=1; 
        }
        else if (ground_truth[0][i] == 1 && predicted[0][i]==0){
            confusionmatrix[1][0] +=1; 
        }
        else if (ground_truth[0][i] == 0 && predicted[0][i]== 1){
            confusionmatrix[0][1] +=1; 
        }
        else if (ground_truth[0][i] == 0 && predicted[0][i]== 0){
            confusionmatrix[0][0] +=1; 
        }

    };
}

std::vector<std::vector<int>> InputVectors::compare(){
    std::vector<std::vector<int>> a =  {{1,2}, {3,4}};
    return a;
}