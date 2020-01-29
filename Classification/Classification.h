#ifndef classification_hpp
#define classification_hpp
#endif
#include <stdio.h>
#include <math.h>
#include <map>
#include "InputVectors/input.hpp"
#include <vector>
#include <iostream>


class Classification {

public:
    Classification(InputVectors input){
        i = input;

    };
    InputVectors i;

    virtual std::vector <float> accuracy() = 0;
    virtual float misclassification() = 0;
    virtual std::vector<float> precision() = 0;
    virtual std::vector<float> recall() = 0;
    virtual std::vector<float> FPrate() = 0;
    virtual std::vector<float> specificity() = 0;
    virtual float prevalence() = 0;
    virtual std::vector<float> Fmeasure() = 0;
    virtual std::vector<float> Gmeasure() = 0;
    //virtual float precisionMultiClass(int pos) = 0;
    //virtual float recallMultiClass(int pos) = 0;
    //virtual float F1ScoreMultiClass(int pos) = 0;
    virtual float macroPrecision() = 0;
    virtual float macroRecall() = 0;
    virtual float macroF1Score() =0;
    virtual float weightedF1() = 0;
    virtual float weightedRecall() =0;
    virtual float weightedPrecision() =0;
    virtual std::vector<int> getWeights()=0;
    virtual float microF1Score() = 0;
    virtual float jaccardCoeff() = 0;
    virtual float matthewsCoeff() = 0;
    virtual std::vector<float> discriminantPower()=0;
    virtual std::vector<float> markedness()=0;
    virtual std::vector<float> balancedClassificationRate() = 0;
    virtual std::vector<float> geometricMean() = 0;
    virtual std::vector<float> optPrecision() = 0;
    virtual std::vector<float> NPV() = 0;
    virtual float hamming() = 0;
    virtual float subset01() = 0;
    virtual float kappa() = 0;
    virtual float falseNegativeRate() = 0;
    virtual std::vector<float> adjustedFmeasure() = 0;
    virtual std::vector<float> adjustedGmeasure() = 0;
    virtual std::vector<float> positiveLR() = 0;
    virtual std::vector<float> negativeLR() = 0;
    virtual std::vector<float> youdenIndex() = 0;
    virtual std::vector<float> balanceError() = 0;
    virtual std::vector<float> DOR() = 0;


    //std::map<std::string, float> getAllMetrics();

};







