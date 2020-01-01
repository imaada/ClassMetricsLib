#include "classification.hpp"


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