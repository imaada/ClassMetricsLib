#ifndef classification_hpp
#define classification_hpp
#include <stdio.h>
#include <math.h>
#include "BinaryClassification.h"

#endif

#include "InputVectors/input.hpp"
#include <vector>
#include <iostream>

enum ClassificationType {
    BINARY, MARY
};

class Classification {

public:
    Classification(InputVectors input){
        i = input;

    };
    InputVectors i;

    virtual float accuracy() = 0;
    virtual float misclassification() = 0;
    virtual float precision() = 0;
    virtual float recall() = 0;
    virtual float FPrate() = 0;
    virtual float specificity() = 0;
    virtual float prevalence() = 0;
    virtual float Fmeasure() = 0;
    virtual float Gmeasure() = 0;
};



class MaryClassification : public Classification {
public:
};


class ClassificationFatory {

public:


    ClassificationFatory(ClassificationType type, InputVectors i){
        switch(type){
            case BINARY:{
                classification = new BinaryClassification(i);
                break;

            }

            default: {
//                classification = new Classification(i);
                break;
            }
        }
    };

    Classification *classification;


};
