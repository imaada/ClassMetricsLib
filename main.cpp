#include <iostream>
#include "Classification/classification.hpp"
#include "vector"

int main() {
    std::vector<std::vector<int> > GT { { 1 },
                                         { 0 } };

    std::vector<std::vector<int> > PR { { 1 },
                                         { 1 } };

    InputVectors i;
    i.setConfusionMatrix(GT, PR);

    ClassificationType b = BINARY;

    ClassificationFatory *cf = new ClassificationFatory(b, i);
    Classification * c = cf->classification;

    std::cout << "Accuracy is: " << c->accuracy() << "%" << std::endl;
    std::cout << "Misclassification is: " << c->misclassification() << "%" << std::endl;
    std::cout << "Precision is: " << c->precision() << "%" << std::endl;
    std::cout << "Recall is: " << c->recall() << "%" << std::endl;
    std::cout << "False-Positive-rate is: " << c->FPrate() << "%" << std::endl;
    std::cout << "Specificity is: " << c->specificity() << "%" << std::endl;
    std::cout << "Prevalence is: " << c->prevalence() << "%" << std::endl;
    std::cout << "F-measure is: " << c->Fmeasure() << "%" << std::endl;
    std::cout << "G-measure is: " << c->Gmeasure() << "%" << std::endl;

    std::cout << "Confusion Matrix is: "<< std::endl;
    std::vector<std::vector<int> > vec = i.getConfustionMatrix();

    for (int x = 0; x < vec.size(); x++)
    {
        for (int j = 0; j < vec[x].size(); j++)
        {
            std::cout << vec[x][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;

}
