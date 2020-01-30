#include <iostream>
//#include "Classification/classification.hpp"
//#include "Classification/BinaryClassification.h"
#include "ClassificationFactory.h"
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

    std::cout << "Accuracy is: ";
    std::vector<float> acc1 = e->accuracy();
    for (int x=0; x <acc1.size();x++){
        std::cout << acc1[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Misclassification is: " << e->misclassification() << std::endl;

    std::cout << "Macro F1 Score is: " << e->macroF1Score() << std::endl;
    std::cout << "Macro Recall is: " << e->macroRecall() << std::endl;
    std::cout << "Macro Precision is: " << e->macroPrecision() << std::endl;
    std::cout << "Weighted Precision is: " << e->weightedPrecision() << std::endl;
    std::cout << "Weighted Recall is: " << e->weightedRecall()  << std::endl;
    std::cout << "Weighted F1 Score is: " << e->weightedF1() << std::endl;

    std::cout << "Negative Predictive Value per class is: " << std::endl;
    std::vector<float> npv1 = e->NPV();
    for (int x=0; x <npv1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< npv1[x]  << std::endl;}

    std::cout << "Recall per class is: " << std::endl;
    std::vector<float> rec1 = e->recall();
    for (int x=0; x <rec1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< rec1[x]  << std::endl;}

    std::cout << "Precision per class is: "<<std::endl;
    std::vector<float> pr1 = e->precision();
    for (int x=0; x <pr1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< pr1[x]  << std::endl;}

    std::cout << "F1 Score per class is: "<<std::endl;
    std::vector<float> f1 = e->Fmeasure();
    for (int x=0; x <f1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< f1[x]  << std::endl;}

    std::cout << "Micro F1 Score is: " << e->microF1Score() << std::endl;

    std::cout << "G-Measure per class is: "<< std::endl;
    std::vector<float> gm1 = e->Gmeasure();
    for (int x=0; x <gm1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< gm1[x]  << std::endl;}

    std::cout << "Discriminant Power per class is: "<< std::endl;
    std::vector<float> dp1 = e->discriminantPower();
    for (int x=0; x <dp1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< dp1[x]  << std::endl;}

    std::cout << "Markedness per class is: "<< std::endl;
    std::vector<float> mk1 = e->markedness();
    for (int x=0; x <mk1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< mk1[x]  << std::endl;}

    std::cout << "Balanced Classification Rate per class is: "<< std::endl;
    std::vector<float> bcr1 = e->balancedClassificationRate();
    for (int x=0; x <bcr1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< bcr1[x]  << std::endl;}

    std::cout << "Balanced Error per class is: "<< std::endl;
    std::vector<float> be1 = e->balanceError();
    for (int x=0; x <be1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< be1[x]  << std::endl;}

    std::cout << "Geometric Mean per class is: "<< std::endl;
    std::vector<float> gmean = e->geometricMean();
    for (int x=0; x <gmean.size();x++){ std::cout << "Class #"<< x+1 << ": "<< gmean[x]  << std::endl;}

    std::cout << " Optimal Precision per class is: "<< std::endl;
    std::vector<float> opt = e->optPrecision();
    for (int x=0; x <opt.size();x++){ std::cout << "Class #"<< x+1 << ": "<< opt[x]  << std::endl;}

    std::cout << "Kappa Score is: " << e->kappa()  << std::endl;

    std::cout << "Diagnostic Odds Ratio per class is: "<< std::endl;
    std::vector<float> dor = e->DOR();
    for (int x=0; x <dor.size();x++){ std::cout << "Class #"<< x+1 << ": "<< dor[x]  << std::endl;}

    std::cout << "Specificity per class is: "<< std::endl;
    std::vector<float> sp1 = e->specificity();
    for (int x=0; x <sp1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< sp1[x]  << std::endl;}

    std::cout << "False Positive Rate per class is: "<< std::endl;
    std::vector<float> fpr1 = e->FPrate();
    for (int x=0; x <fpr1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< fpr1[x]  << std::endl;}

    std::cout << "Youden's Index per class is: "<< std::endl;
    std::vector<float> yi1 = e->youdenIndex();
    for (int x=0; x <yi1.size();x++){ std::cout << "Class #"<< x+1 << ": "<< yi1[x]  << std::endl;}

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
    std::cout << std::endl;

    std::cout << "Accuracy is: ";
    std::vector<float> acc = c->accuracy();
    for (int x=0; x <acc.size();x++){
        std::cout << acc[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Misclassification is: " << c->misclassification() << std::endl;

    std::cout << "Precision is: ";
    std::vector<float> pr = c->precision();
    for (int x=0; x <pr.size();x++){
        std::cout << pr[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Recall is: ";
    std::vector<float> rec = c->recall();
    for (int x=0; x <rec.size();x++){
        std::cout << rec[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "False-Positive-rate is: ";
    std::vector<float> fp = c->FPrate();
    for (int x=0; x <fp.size();x++){
        std::cout << fp[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Specificity is: ";
    std::vector<float> sp = c->specificity();
    for (int x=0; x <sp.size();x++){
        std::cout << sp[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Prevalence is: " << c->prevalence() << std::endl;

    std::cout << "F-measure is: ";
    std::vector<float> fm = c->Fmeasure();
    for (int x=0; x <fm.size();x++){
        std::cout << fm[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "G-measure is: ";
    std::vector<float> gm = c->Gmeasure();
    for (int x=0; x <gm.size();x++){
        std::cout << gm[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Jaccard Similarity Coefficient is: " << c->jaccardCoeff() << std::endl;
    std::cout << "Matthews Correlation Coefficient is: " << c->matthewsCoeff() << std::endl;

    std::cout << "Negative Predictive Value is: ";
    std::vector<float> npv = c->NPV();
    for (int x=0; x <npv.size();x++){
        std::cout << npv[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Discriminant Power is: ";
    std::vector<float> dp = c->discriminantPower();
    for (int x=0; x <dp.size();x++){
        std::cout << dp[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Optimal Precision is: ";
    std::vector<float> op = c->optPrecision();
    for (int x=0; x <op.size();x++){
        std::cout << op[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Markedness is: ";
    std::vector<float> mk = c->markedness();
    for (int x=0; x <mk.size();x++){
        std::cout << mk[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Balanced Classification Rate is: ";
    std::vector<float> bcr = c->balancedClassificationRate();
    for (int x=0; x <bcr.size();x++){
        std::cout << bcr[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Geometric Mean is: ";
    std::vector<float> geo = c->geometricMean();
    for (int x=0; x <geo.size();x++){
        std::cout << geo[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Kappa Score is " << c->kappa() << std::endl;

    std::cout << "False Negative Rate is: " << c->falseNegativeRate() <<  std::endl;

    std::cout << "Adjusted F-measure is: ";
    std::vector<float> afm = c->adjustedFmeasure();
    for (int x=0; x <afm.size();x++){
        std::cout << afm[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Adjusted G-measure is: ";
    std::vector<float> agm = c->adjustedGmeasure();
    for (int x=0; x <agm.size();x++){
        std::cout << agm[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Positive Likelihood Ratio is: ";
    std::vector<float> plr = c->positiveLR();
    for (int x=0; x <plr.size();x++){
        std::cout << plr[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Negative Likelihood Ratio is: ";
    std::vector<float> nlr = c->negativeLR();
    for (int x=0; x <nlr.size();x++){
        std::cout << nlr[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Youden's Index is: ";
    std::vector<float> yi = c->youdenIndex();
    for (int x=0; x <yi.size();x++){
        std::cout << yi[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Balanced Error Rate is: ";
    std::vector<float> be = c->balanceError();
    for (int x=0; x <be.size();x++){
        std::cout << be[x] << " ";
    }
    std::cout << std::endl;

    std::cout << "Diagnostic Odds Ratio is: ";
    std::vector<float> dor1 = c->DOR();
    for (int x=0; x <dor1.size();x++){ std::cout << dor1[x] << " ";}
    std::cout << std::endl;
    return 0;

}
