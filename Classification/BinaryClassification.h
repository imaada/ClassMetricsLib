//
// Created by i_maa on 27-Jan.-2020.
//

#ifndef BINARYCLASSIFICATION_H
#define BINARYCLASSIFICATION_H

#endif //BINARYCLASSIFICATION_H

#include "Classification.h"

class BinaryClassification : public Classification {

public:
    BinaryClassification(InputVectors input);
    float TP;
    float TN;
    float FP;
    float FN;
    std::vector<std::vector<int>>  matrix;
    float instances;

    std::vector<float> accuracy();//PPV
    float misclassification();
    std::vector<float> precision();
    std::vector<float> recall();//TPR or sensitivity or hit rate
    std::vector<float> FPrate();
    std::vector<float> specificity();//TNR or inverse recall
    std::vector<float> NPV();
    std::vector<float> discriminantPower();
    std::vector<float> markedness();
    std::vector<float> balancedClassificationRate();
    std::vector<float> geometricMean();
    std::vector<float> optPrecision();
    std::vector<float> Fmeasure();
    std::vector<float> Gmeasure();
    std::vector<float> adjustedFmeasure();
    std::vector<float> adjustedGmeasure();
    std::vector<float> positiveLR();
    std::vector<float> negativeLR();
    std::vector<float> youdenIndex();
    std::vector<float> balanceError();
    std::vector<float> DOR();

    float kappa();
    float falseNegativeRate();
    float prevalence();
    float jaccardCoeff();
    float matthewsCoeff();//A coefficient of 1 indicates a perfect prediction,
                         // -1 represents total disagreement between prediction and true

};
