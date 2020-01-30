//
// Created by i_maa on 28-Jan.-2020.
//

#ifndef CLASSIFICATIONFACTORY_H
#define CLASSIFICATIONFACTORY_H

#endif //CLASSMETRICS_CLASSIFICATIONFACTORY_H

#include "MultiLabelClassification.h"
//#include "MaryClassification.h"

enum ClassificationType {
    BINARY, MARY, MULTILABEL
};


class ClassificationFactory {

public:


    ClassificationFactory(ClassificationType type, InputVectors i){
        switch(type){
            case BINARY:{
                classification = new BinaryClassification(i);
                break;

            }

            case MARY:{
                classification = new MaryClassification(i);
                break;
            }

            case MULTILABEL:{
                classification = new MultiLabelClassification(i);
                break;
            }

        }
    };

    Classification *classification;


};