//
// Created by i_maa on 05-Jan.-2020.
//

#ifndef CLASSMETRICSLIB_BINARYCLASSIFICATION_H
#define CLASSMETRICSLIB_BINARYCLASSIFICATION_H

#include "classification.hpp"
#include <stdio.h>
#include <math.h>

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


#endif //CLASSMETRICSLIB_BINARYCLASSIFICATION_H
