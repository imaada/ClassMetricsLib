//
// Created by i_maa on 28-Jan.-2020.
//

#include "MultiLabelClassification.h"

MultiLabelClassification::MultiLabelClassification(InputVectors i) : Classification (i) {
    groundTruth  = i.getGroundTruth();
    predictedInput = i.getPredicted();
}

float MultiLabelClassification::hamming() {
    float num = 0;
    float denum = groundTruth.size()* groundTruth[0].size();
    for (int i = 0; i < groundTruth.size(); i++) {
        for (int j = 0; j < groundTruth[0].size(); j++) {
            if (groundTruth[i][j] != predictedInput[i][j]){num +=1;}
        }
    }
    return num/denum;
}

float MultiLabelClassification::subset01() {
    float num = 0;
    float denum = groundTruth.size();
    for (int i = 0; i < groundTruth.size(); i++) {
        if (groundTruth[i] != predictedInput[i]) { num += 1; }
    }
    return num/denum;
}
