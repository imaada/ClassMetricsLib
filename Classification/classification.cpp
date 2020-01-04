#include "classification.hpp"
#include "vector"

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

float BinaryClassification::accuracy(){ 
    return InputVectors::getConfustionMatrix();
} 

float BinaryClassification::Fmeasure(){

}

float BinaryClassification::Gmeasure(){

}

float BinaryClassification::misclassification(){

}

float BinaryClassification::precision(){

}

float BinaryClassification::prevalence(){

}

float BinaryClassification::recall(){

}

float BinaryClassification::specificity(){

}