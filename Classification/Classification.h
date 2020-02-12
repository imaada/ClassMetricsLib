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

    virtual std::vector <float> accuracy() {};
    virtual float misclassification() {};
    virtual std::vector<float> precision() {};
    virtual std::vector<float> recall() {};
    virtual std::vector<float> FPrate() {};
    virtual std::vector<float> specificity() {};
    virtual float prevalence() {};
    virtual std::vector<float> Fmeasure() {};
    virtual std::vector<float> Gmeasure() {};
    virtual float macroPrecision() {};
    virtual float macroRecall() {};
    virtual float macroF1Score() {};
    virtual float weightedF1() {};
    virtual float weightedRecall() {};
    virtual float weightedPrecision() {};
    virtual float microF1Score() {};
    virtual float jaccardCoeff() {};
    virtual float matthewsCoeff() {};
    virtual std::vector<float> discriminantPower() {};
    virtual std::vector<float> markedness() {};
    virtual std::vector<float> balancedClassificationRate() {};
    virtual std::vector<float> geometricMean() {};
    virtual std::vector<float> optPrecision() {};
    virtual std::vector<float> NPV() {};
    virtual float hamming() {};
    virtual float subset01() {};
    virtual float kappa() {};
    virtual float falseNegativeRate() {};
    virtual std::vector<float> adjustedFmeasure() {};
    virtual std::vector<float> adjustedGmeasure() {};
    virtual std::vector<float> positiveLR() {};
    virtual std::vector<float> negativeLR() {};
    virtual std::vector<float> youdenIndex() {};
    virtual std::vector<float> balanceError() {};
    virtual std::vector<float> DOR() {};


    //std::map<std::string, float> getAllMetrics();

};







