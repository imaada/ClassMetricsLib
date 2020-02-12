//
// Created by i_maa on 28-Jan.-2020.
//

#ifndef CLASSMETRICS_MULTILABELCLASSIFICATION_H
#define CLASSMETRICS_MULTILABELCLASSIFICATION_H

#include "MaryClassification.h"

class MultiLabelClassification : public Classification {
public:
    MultiLabelClassification (InputVectors i);
    std::vector<std::vector<int>> groundTruth;
    std::vector<std::vector<int>> predictedInput;

    float hamming();

    float subset01();;

};

#endif //CLASSMETRICS_MULTILABELCLASSIFICATION_H
