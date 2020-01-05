#ifndef classification_hpp
#define classification_hpp
#include <stdio.h>
#include <math.h>

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

class BinaryClassification : public Classification {

public:
    BinaryClassification(InputVectors input) : Classification(input){
        matrix = i.getConfustionMatrix();
        TP =(float) matrix[0][0];
        TN =(float) matrix[1][1];
        FP =(float) matrix[0][1];
        FN =(float) matrix[1][0];
        instances = TP + TN + FP + FN;


    }
    float TP;
    float TN;
    float FP;
    float FN;
    std::vector<std::vector<int>>  matrix;
    float instances;

    float accuracy(){

        float m = (TP + TN) / instances;
        return m*100;
    };

    float misclassification(){
        float m = 1- ((TP + TN) / instances);
        return m*100;
    };
    float precision(){
        float m = (TP) / (TP + FP);
        return m*100;
    };
    float recall(){
        float m = ((TP) / (TP + FN));
        return m*100;
    };
    float FPrate(){
        float m = (FP) / (TN + FP);
        return m*100;
    };
    float specificity(){
        float m = 1-((FP) / (TN + FP));
        return m*100;
    };
    float prevalence(){
        float m = (FN + TP) / (instances);
        return m*100;
    };
    float Fmeasure(){
        float m = (2*((TP) / (TP + FN))*((TP) / (TP + FP)))/(((TP) / (TP + FP))+((TP) / (TP + FN)));
        return m*100;
    };
    float Gmeasure(){
        float m = sqrt(((TP) / (TP + FN))*((TP) / (TP + FP)));
        return m*100;
    };

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
