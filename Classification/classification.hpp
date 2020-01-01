#ifndef classification_hpp
#define classification_hpp
#include <stdio.h>

#endif

#include "InputVectors/input.hpp"
#include <vector>
#include <iostream>

enum ClassificationType {
    BINARY, MARY
};

class Classification {
public:
};

class BinaryClassification : public Classification {

public:
    float accuray();


};

class MaryClassification : public Classification {
public:
};


class ClassificationFatory {

public:
    Classification createClassification(ClassificationType type);

};
