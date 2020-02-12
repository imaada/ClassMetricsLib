//
// Created by i_maa on 28-Jan.-2020.
//

#ifndef CLASSMETRICS_MARYCLASSIFICATION_H
#define CLASSMETRICS_MARYCLASSIFICATION_H

#include "BinaryClassification.h"

class MaryClassification : public Classification {
public:
    MaryClassification (InputVectors input);
    std::vector<std::vector<int>> matrix;
    int totalInstances;
    //1D vector with instances per class from GT
    std::vector<int> weights;
    std::vector<int> FN;
    std::vector<int> FP;
    std::vector<int> TP;
    std::vector<int> TN;

    std::vector <float> accuracy();;
    std::vector<float> Gmeasure();;
    std::vector<float> discriminantPower();
    std::vector<float> markedness();
    std::vector<float> balancedClassificationRate();
    std::vector<float> geometricMean();
    std::vector<float> optPrecision();
    std::vector<float> NPV();
    std::vector<float> youdenIndex();
    std::vector<float> balanceError();
    std::vector<float> recall();
    std::vector<float> precision();
    std::vector<float> Fmeasure();
    std::vector<float> DOR();
    std::vector<float> FPrate();
    std::vector<float> specificity();
    float misclassification();
    float macroPrecision();
    float macroRecall();
    float macroF1Score();
    float weightedPrecision();
    float weightedRecall();
    float weightedF1();
    float microF1Score();
    float kappa();
};


#endif //CLASSMETRICS_MARYCLASSIFICATION_H
