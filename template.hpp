
#ifndef template_hpp
#define template_hpp
#include <stdio.h>

#endif /* template_hpp */

#include <vector>
#include <iostream>

enum ClassificationType {
    BINARY, MARY
};

class Classification {
public:
//    Classification();
};

class BinaryClassification : public Classification {
  
public:

//Calculate confusion matrix quantities
    // BinaryClassification(char GT[], char predicted[]);
    float accuray();

    
};

class MaryClassification : public Classification {

public:
};


class ClassificationFatory {
    
public:
//    ClassificationFatory();
    Classification createClassification(ClassificationType type);
    
};


class InputVectors {
    
    int TP;
    int FP;
    int FN;
    int FP;

    public:
        InputVectors(std::vector<std::vector<int>> ground_truth, std::vector<std::vector<int>> predicted);
        std::vector<std::vector<int>> compare();

};

