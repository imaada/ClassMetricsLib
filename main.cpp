#include <iostream>
#include "Classification/classification.hpp"
#include "vector"

int main() {
//    BINARY INPUT EXAMPLE
    std::vector<std::vector<int> > GT { { 1 },
            { 0 },
            { 1 },
            { 1 } };

    std::vector<std::vector<int> > PR { { 1 },
                                        { 1 },
                                        { 0 },
                                        { 1 } };

    std::vector<std::vector<int> > GTMulti {  //TPs
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 0, 1, 0 },
                                             { 0, 1, 0 },
                                             { 0, 0, 1 },
                                             { 0, 0, 1 },
                                             { 0, 0, 1 },
                                             { 0, 0, 1 },
                                             { 0, 0, 1 },
                                             { 0, 0, 1 },
                                             //Other
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 0, 1, 0 },
                                             { 0, 1, 0 },
                                             { 0, 1, 0 },
                                             { 0, 1, 0 },
                                             { 0, 1, 0 },
                                             { 0, 1, 0 },

                                             { 0, 1, 0 },
                                             { 0, 1, 0 },

                                             { 0, 0, 1 },
                                             { 0, 0, 1 },
                                             { 0, 0, 1} };

    std::vector<std::vector<int> > PRMulti {  //TPs
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 0, 1, 0 },
                                             { 0, 1, 0 },
                                             { 0, 0, 1 },
                                             { 0, 0, 1 },
                                             { 0, 0, 1 },
                                             { 0, 0, 1 },
                                             { 0, 0, 1 },
                                             { 0, 0, 1 },
                                             //Other
                                             { 0, 1, 0 },
                                             { 0, 0, 1 },
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 1, 0, 0 },

                                             { 0, 0, 1 },
                                             { 0, 0, 1 },

                                             { 1, 0, 0 },
                                             { 1, 0, 0 },
                                             { 1, 0, 0} };

    std::vector<std::vector<int> > GTMultiLabel {  //TPs
            { 1, 0, 1 },
            { 1, 0, 1 },
            { 1, 0, 1 },
            { 1, 0, 1 },
            { 0, 1, 1 },
            { 0, 1, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            //Other
            { 1, 0, 0 },
            { 1, 0, 0 },
            { 0, 1, 0 },
            { 0, 1, 0 },
            { 0, 1, 0 },
            { 0, 1, 0 },
            { 0, 1, 0 },
            { 0, 1, 0 },

            { 0, 1, 0 },
            { 0, 1, 0 },

            { 0, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1} };

    std::vector<std::vector<int> > PRMultiLabel {  //TPs
            { 1, 0, 1 },
            { 1, 0, 1 },
            { 1, 0, 1 },
            { 1, 0, 1 },
            { 0, 1, 1 },
            { 0, 1, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            { 0, 0, 1 },
            //Other
            { 0, 1, 0 },
            { 0, 0, 1 },
            { 1, 0, 0 },
            { 1, 0, 0 },
            { 1, 0, 0 },
            { 1, 0, 0 },
            { 1, 0, 0 },
            { 1, 0, 0 },

            { 0, 0, 1 },
            { 0, 0, 1 },

            { 1, 0, 0 },
            { 1, 0, 0 },
            { 1, 0, 0} };

    InputVectors h;
    h.setConfusionMatrix(GTMultiLabel, PRMultiLabel);
    ClassificationType f = MULTILABEL;
    ClassificationFactory *gf = new ClassificationFactory (f, h);
    Classification * g = gf ->classification;
    std::cout << "Multi Label Test Case" << std::endl;
    std::cout << "Hamming Loss is: " << g->hamming() << std::endl;
    std::cout << "Subset Zero-One-Loss is: " << g->subset01() << std::endl;
    std::cout << std::endl;

    std::cout << "---------------------------------------------------------------------------------------" << std::endl;

    InputVectors j;
    j.setConfusionMatrix(GTMulti, PRMulti);
    ClassificationType d = MARY;
    ClassificationFactory *ef = new ClassificationFactory (d, j);
    Classification * e = ef->classification;
    std::cout << "Multi Class Test Case" << std::endl;
    std::vector<std::vector<int> > vec2 = j.getConfustionMatrix();
    std::vector<int> weights = e->getWeights();

    std::cout << "Per label instances are: " << std::endl;
    for (int x=0; x <weights.size();x++){
        std::cout << weights[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Confusion Matrix is: "<< std::endl;
    for (int x = 0; x < vec2.size(); x++)
    {
        for (int j = 0; j < vec2[x].size(); j++)
        {
            std::cout << vec2[x][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Precision for label 1 is: " << e->precisionMultiClass(1) << "%" << std::endl;
    std::cout << "Precision for label 2 is: " << e->precisionMultiClass(2) << "%" << std::endl;
    std::cout << "Precision for label 3 is: " << e->precisionMultiClass(3) << "%" << std::endl;
    std::cout << "Recall for label 1 is: " << e->recallMultiClass(1) << "%" << std::endl;
    std::cout << "Recall for label 2 is: " << e->recallMultiClass(2) << "%" << std::endl;
    std::cout << "Recall for label 3 is: " << e->recallMultiClass(3) << "%" << std::endl;
    std::cout << "F1 Score for label 1 is " << e->F1ScoreMultiClass(1) << "%" << std::endl;
    std::cout << "F1 Score for label 2 is " << e->F1ScoreMultiClass(2) << "%" << std::endl;
    std::cout << "F1 Score for label 3 is " << e->F1ScoreMultiClass(3) << "%" << std::endl;
    std::cout << "Macro F1 Score is: " << e->macroF1Score() << "%" << std::endl;
    std::cout << "Macro Recall is: " << e->macroRecall() << "%" << std::endl;
    std::cout << "Macro Precision is: " << e->macroPrecision() << "%" << std::endl;
    std::cout << "Weighted Precision is: " << e->weightedPrecision() << "%" << std::endl;
    std::cout << "Weighted Recall is: " << e->weightedRecall() << "%" << std::endl;
    std::cout << "Weighted F1 Score is: " << e->weightedF1() << "%" << std::endl;
    std::cout << "Micro F1 Score is: " << e->microF1Score() << "%" << std::endl;
    std::cout << std::endl;

    std::cout << "---------------------------------------------------------------------------------------" << std::endl;

    std::cout << "Binary Test Case" << std::endl;
    InputVectors i;
    i.setConfusionMatrix(GT, PR);
    ClassificationType b = BINARY;
    ClassificationFactory *cf = new ClassificationFactory(b, i);
    Classification * c = cf->classification;
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
    std::cout << "Accuracy is: " << c->accuracy() << "%" << std::endl;
    std::cout << "Misclassification is: " << c->misclassification() << "%" << std::endl;
    std::cout << "Precision is: " << c->precision() << "%" << std::endl;
    std::cout << "Recall is: " << c->recall() << "%" << std::endl;
    std::cout << "False-Positive-rate is: " << c->FPrate() << "%" << std::endl;
    std::cout << "Specificity is: " << c->specificity() << "%" << std::endl;
    std::cout << "Prevalence is: " << c->prevalence() << "%" << std::endl;
    std::cout << "F-measure is: " << c->Fmeasure() << "%" << std::endl;
    std::cout << "G-measure is: " << c->Gmeasure() << "%" << std::endl;
    std::cout << "Jaccard Similarity Coefficient is: " << c->jaccardCoeff() << std::endl;
    std::cout << "Matthews Correlation Coefficient is: " << c->matthewsCoeff() << std::endl;
    std::cout << "Negative Predictive Value is: " << c->NPV() << "%" << std::endl;
    std::cout << "Discriminant Power is: " << c->discriminantPower() << std::endl;
    std::cout << "Optimal Precision is: " << c->optPrecision() << "%" << std::endl;
    std::cout << "Markedness is: " << c->markedness() << std::endl;
    std::cout << "Balanced Classification Rate is: " << c->balancedClassificationRate() << "%" << std::endl;
    std::cout << "Geometric Mean is: " << c->geometricMean() << std::endl;


    return 0;

}
