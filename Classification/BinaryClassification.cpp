//
// Created by i_maa on 11-Feb.-2020.
//

#include "BinaryClassification.h"

BinaryClassification::BinaryClassification(InputVectors input) : Classification(input){
    matrix = i.getConfustionMatrix();
    TP =(float) matrix[0][0];
    TN =(float) matrix[1][1];
    FP =(float) matrix[0][1];
    FN =(float) matrix[1][0];
    instances = TP + TN + FP + FN;


}

std::vector<float> BinaryClassification::accuracy() {

    std::vector<float> m(1);
    int i =0;
    m[0] = (((float)TP + (float)TN) / (float) instances);
    return m;
}

float BinaryClassification::misclassification() {
    float m = 1- ((TP + TN) / instances);
    return m;
}

std::vector<float> BinaryClassification::precision() {
    std::vector<float> m(1);
    m[0] = (TP) / (TP + FP);
    return m;
}

std::vector<float> BinaryClassification::recall() {
    std::vector<float> m(1);
    m[0] = ((TP) / (TP + FN));
    return m;
}

std::vector<float> BinaryClassification::FPrate() {
    std::vector<float>  m(1);
    m[0] = (FP) / (TN + FP);
    return m;
}

std::vector<float> BinaryClassification::specificity() {
    std::vector<float> m(1);
    m = this->FPrate();
    m[0] = 1-m[0];
    return m;
}

float BinaryClassification::prevalence() {
    float m = (FN + TP) / (instances);
    return m;
}

std::vector<float> BinaryClassification::Fmeasure() {
    std::vector<float> m(1);
    m = this->recall();
    std::vector<float> n(1);
    n = this -> precision();
    m[0] = (2*m[0]*n[0])/(m[0] + n[0]);
    return m;
}

std::vector<float> BinaryClassification::Gmeasure() {
    std::vector<float> m(1);
    m = this->recall();
    std::vector<float> n(1);
    n = this -> precision();
    m[0] = sqrt(m[0]*n[0]);
    return m;
}

float BinaryClassification::jaccardCoeff() {
    float m;
    m = TP/(TP + FP + FN);
    return m ;
}

float BinaryClassification::matthewsCoeff() {
    float num = (TP*TN) - (FP*FN);
    float denum= sqrt((TP+FP)*(TP+FN)*(TN+FP)*(TN+FN));
    return num/denum;
}

std::vector<float> BinaryClassification::NPV() {
    std::vector<float> n(1);
    n[0] = TN/(FN+TN);
    return n;
}

std::vector<float> BinaryClassification::discriminantPower() {
    std::vector<float> dp(1);
    std::vector<float> m(1);
    m = this->recall();
    std::vector<float> n(1);
    n = this -> specificity();
    float coeff = sqrt(3)/M_PI;
    dp[0] = coeff*(log10((m[0])/(1-(n[0]))) + log10((n[0])/(1-(m[0]))));
    return dp;
}

std::vector<float> BinaryClassification::markedness() {
    std::vector<float> m(1);
    m = this->precision();
    std::vector<float> n(1);
    n = this -> NPV();
    m[0] = (m[0]) + (n[0]) - 1;
    return m;
}

std::vector<float> BinaryClassification::balancedClassificationRate() {
    std::vector<float> m(1);
    m = this->recall();
    std::vector<float> n(1);
    n = this -> specificity();
    m[0] = ((m[0])+(n[0]))/2;
    return m;
}

std::vector<float> BinaryClassification::geometricMean() {
    std::vector<float> m(1);
    m = this->recall();
    std::vector<float> n(1);
    n = this -> specificity();
    m[0] = sqrt((m[0])*(n[0]));
    return m;

}

std::vector<float> BinaryClassification::optPrecision() {
    std::vector<float> m(1);
    m = this->recall();
    std::vector<float> n(1);
    n = this -> specificity();
    std::vector<float> acc(1);
    acc = this->accuracy();
    std::vector<float> opt(1);

    opt[0] = (acc[0]) - ( abs(m[0]-n[0]) / (m[0]+n[0]) );
    return opt;

}

float BinaryClassification::kappa() {
    float agree = (TP + TN) /instances;
    float chanceAgree1 = ((TP + FN)/ instances) * ((TP + FP)/instances);
    float chanceAgree2 = ((TP + FP)/instances) * ((FP + TN)/instances);
    float chanceAgree = chanceAgree1 + chanceAgree2;
    float m = (agree - chanceAgree)/(1- chanceAgree);

    return m;
}

float BinaryClassification::falseNegativeRate() {
    float m = FN /(FP + TN);
    return m;
}

std::vector<float> BinaryClassification::adjustedFmeasure() {
//        returning f2 score and not agf
    std::vector<float> agf(1);
    float invPrecision = TN/(TN + FN);
    float invRecall = TN/(TN + FP);
    float invF = ((1.25)*(invPrecision*invRecall)) / (0.25*invPrecision + invRecall);
    float f2 = (5*TP) / (5*TP + 4*FN + FP);
    agf[0] = sqrt(f2 * invF);
    return agf;
}

std::vector<float> BinaryClassification::adjustedGmeasure() {
    std::vector<float> gm(1);
    gm = this->geometricMean();
    std::vector<float> sp(1);
    sp = this -> specificity();
    std::vector<float> rec(1);
    rec = this->recall();
    std::vector<float> agm(1);

    if ( rec[0] == 0.0) {
        agm[0] = 0.0;
        return agm;
    }
    else {
        agm[0] = (gm[0] + sp[0] * (FP + TN)) / (1 + FP + TN);
        return agm;
    }
}

std::vector<float> BinaryClassification::positiveLR() {
    std::vector<float> sp(1);
    sp = this -> specificity();
    std::vector<float> rec(1);
    rec = this->recall();
    std::vector<float> m(1);
    m[0] = (rec[0]) / (1 - sp[0]);
    return m;
}

std::vector<float> BinaryClassification::negativeLR() {
    std::vector<float> sp(1);
    sp = this -> specificity();
    std::vector<float> rec(1);
    rec = this->recall();
    std::vector<float> m(1);

    if (sp[0] != 0){
        m[0] = (1 - rec[0]) / (sp[0]);
        return m;
    }
    else {m[0] = 0.0; return m;}
}

std::vector<float> BinaryClassification::youdenIndex() {
    std::vector<float> sp(1);
    sp = this -> specificity();
    std::vector<float> rec(1);
    rec = this->recall();
    std::vector<float> m(1);
    m[0] = rec[0] + sp[0] - 1;
    return m;
}

std::vector<float> BinaryClassification::balanceError() {
    std::vector<float> bcr(1);
    bcr = this -> balancedClassificationRate();
    std::vector<float> m(1);

    m[0] = 1 - bcr[0];
    return m;
}

std::vector<float> BinaryClassification::DOR() {
    std::vector<float> m(1);
    m[0] = ((float)TP*(float)TN)/ ((float)FP*(float)FN);
    return m;
}
