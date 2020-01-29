//
// Created by i_maa on 28-Jan.-2020.
//

#ifndef CLASSMETRICS_MULTILABELCLASSIFICATION_H
#define CLASSMETRICS_MULTILABELCLASSIFICATION_H

#include "MaryClassification.h"

class MultiLabelClassification : public Classification {
public:
    MultiLabelClassification (InputVectors i): Classification (i) {
        groundTruth  = i.getGroundTruth();
        predictedInput = i.getPredicted();
    }

    std::vector<std::vector<int>> groundTruth;
    std::vector<std::vector<int>> predictedInput;

    float hamming() {
        float num = 0;
        float denum = groundTruth.size()* groundTruth[0].size();
        for (int i = 0; i < groundTruth.size(); i++) {
            for (int j = 0; j < groundTruth[0].size(); j++) {
                if (groundTruth[i][j] != predictedInput[i][j]){num +=1;}
            }
        }
        return num/denum;
    }

    float subset01() {
        float num = 0;
        float denum = groundTruth.size();
        for (int i = 0; i < groundTruth.size(); i++) {
            if (groundTruth[i] != predictedInput[i]) { num += 1; }
        }
        return num/denum;
    };

    std::vector <float> accuracy()  {std::vector<float> mo(1);
        return mo;}
    float misclassification() {return 0.0;}
    std::vector<float> precision() {std::vector<float> m(groundTruth[0].size()); return m;}
    std::vector<float> recall() {std::vector<float> m(groundTruth[0].size()); return m;}
    std::vector<float> FPrate() {std::vector<float> m(groundTruth[0].size()); return m;}
    std::vector<float> specificity() {std::vector<float> m(groundTruth[0].size()); return m;}
    float prevalence() {return 0.0;}
    std::vector<float> Fmeasure() {std::vector<float> m(groundTruth[0].size()); return m;}
    std::vector<float> Gmeasure() {std::vector<float> m(groundTruth[0].size()); return m;}
    //float precisionMultiClass(int pos) {return 0.0;}
    //float recallMultiClass(int pos) {return 0.0;}
    //float F1ScoreMultiClass(int pos) {return 0.0;}
    float macroPrecision() {return 0.0;}
    float macroRecall() {return 0.0;}
    float macroF1Score() {return 0.0;}
    float weightedF1() {return 0.0;}
    float weightedRecall() {return 0.0;}
    float weightedPrecision() {return 0.0;}
    std::vector<int> getWeights(){std::vector<int> m(groundTruth[0].size()); return m;}
    float microF1Score() {return 0.0;}
    float jaccardCoeff() {return 0.0;}
    float matthewsCoeff() {return 0.0;}
    std::vector<float> discriminantPower(){std::vector<float> m(groundTruth[0].size()); return m;}
    std::vector<float> markedness(){std::vector<float> m(groundTruth[0].size()); return m;}
    std::vector<float> balancedClassificationRate() {std::vector<float> m(groundTruth[0].size()); return m;}
    std::vector<float> geometricMean() {std::vector<float> m(groundTruth[0].size()); return m;}
    std::vector<float> optPrecision() {std::vector<float> m(groundTruth[0].size()); return m;}
    std::vector<float> NPV(){std::vector<float> m(groundTruth[0].size()); return m;}
    float kappa() {return 0.0;}
    float falseNegativeRate() {return 0.0;};
    std::vector<float> adjustedFmeasure() {std::vector<float> m(groundTruth[0].size()); return m;};
    std::vector<float> adjustedGmeasure() {std::vector<float> m(groundTruth[0].size()); return m;};
    std::vector<float> positiveLR() {std::vector<float> m(groundTruth[0].size()); return m;};
    std::vector<float> negativeLR() {std::vector<float> m(groundTruth[0].size()); return m;};
    std::vector<float> youdenIndex() {std::vector<float> m(groundTruth[0].size()); return m;};
    std::vector<float> balanceError() {std::vector<float> m(groundTruth[0].size()); return m;};
    std::vector<float> DOR(){ std::vector<float> m(groundTruth[0].size()); return m;}

};

#endif //CLASSMETRICS_MULTILABELCLASSIFICATION_H
