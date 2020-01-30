//
// Created by i_maa on 28-Jan.-2020.
//

#ifndef CLASSMETRICS_MARYCLASSIFICATION_H
#define CLASSMETRICS_MARYCLASSIFICATION_H

#include "BinaryClassification.h"

class MaryClassification : public Classification {
public:
    MaryClassification (InputVectors input) : Classification(input){
        matrix = i.getConfustionMatrix();
        totalInstances =0;
        weights.resize(matrix.size());
        FN.resize(matrix.size());
        FP.resize(matrix.size());
        TP.resize(matrix.size());
        TN.resize(matrix.size());
        for (int h = 0; h < matrix.size(); h++){
            for (int k = 0; k < matrix[0].size(); k++){
                totalInstances += matrix[h][k];
                weights[k] += matrix[h][k];
                if (h != k){
                    FN[k] += matrix[h][k];
                    FP[k] += matrix[k][h];
                }
                else {TP[k] = matrix[h][k];}
            }
        }
        for (int i =0; i< matrix.size(); i++){
            TN[i] = totalInstances - FN[i] - FP[i] - TP[i];
        }

    }
    std::vector<std::vector<int>> matrix;
    int totalInstances;
    //1D vector with instances per class from GT
    std::vector<int> weights;
    std::vector<int> FN;
    std::vector<int> FP;
    std::vector<int> TP;
    std::vector<int> TN;

    std::vector<int> getWeights(){
        return TN;
    }

    std::vector <float> accuracy() {
        std::vector<float> acc(1);
        int totalTP = 0;
        for(int x = 0; x < matrix.size(); x++){
            totalTP += TP[x];
        }
        acc[0] = float(totalTP)/(float) totalInstances;
        return acc;
    };

    float misclassification(){
        std::vector<float> acc(1);
        acc = this->accuracy();
        float miss = 1 - acc[0];
        return miss;
    };
    float prevalence(){ return 0.0;};

    std::vector<float> Gmeasure(){
        std::vector<float> m(matrix.size());
        m = this->recall();
        std::vector<float> n(matrix.size());
        n = this -> precision();
        std::vector<float> gm(matrix.size());
        for (int i =0; i < matrix.size(); i ++) {
            gm[i] = sqrt(m[i]*n[i]);
        }

        return gm;
    };
    float jaccardCoeff(){return 0.0;};
    float matthewsCoeff(){return 0.0;}
    std::vector<float> discriminantPower(){
        std::vector<float> dp(matrix.size());
        std::vector<float> m(matrix.size());
        m = this->recall();
        std::vector<float> n(matrix.size());
        n = this -> specificity();
        float coeff = sqrt(3)/M_PI;
        for (int i = 0; i < matrix.size(); i++){
            dp[i] = coeff*(log10((m[i])/(1-(n[i]))) + log10((n[i])/(1-(m[i]))));
        }
        return dp;
    }
    std::vector<float> markedness(){
        std::vector<float> m(matrix.size());
        m = this->precision();
        std::vector<float> n(matrix.size());
        n = this -> NPV();
        std::vector<float> mk (matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            mk[i] = (m[i]) + (n[i]) - 1;
        }
        return mk;
    }
    std::vector<float> balancedClassificationRate(){
        std::vector<float> bcr(matrix.size());
        std::vector<float> m(matrix.size());
        m = this->recall();
        std::vector<float> n(matrix.size());
        n = this -> specificity();
        for (int i = 0; i < matrix.size(); i++){
            bcr[i] =  ((m[i])+(n[i]))/2;
        }
        return bcr;
    }
    std::vector<float> geometricMean(){
        std::vector<float> gm(matrix.size());
        std::vector<float> m(matrix.size());
        m = this->recall();
        std::vector<float> n(matrix.size());
        n = this -> specificity();
        for (int i  = 0; i < matrix.size(); i++) {
            gm[i] = sqrt((m[i]) * (n[i]));
        }
        return gm;
    }
    std::vector<float> optPrecision(){
        std::vector<float> m(matrix.size());
        m = this->recall();
        std::vector<float> n(matrix.size());
        n = this -> specificity();
        std::vector<float> acc(1);
        acc = this->accuracy();
        std::vector<float> opt(matrix.size());
        for (int i  = 0; i < matrix.size(); i++) {
            opt[i] = (acc[0]) - (abs(m[i] - n[i]) / (m[i] + n[i]));
        }
        return opt;
    }
    std::vector<float> NPV(){
        std::vector<float> npv(matrix.size());
        for (int i  = 0; i < matrix.size(); i++) {
            npv[i] = (float)TN[i] / ((float)FN[i] + (float)TN[i]);
        }
        return npv;
    }
    float hamming() {return 0.0;}
    float subset01() {return 0.0;}
    float falseNegativeRate() {return 0.0;};
    std::vector<float> adjustedFmeasure() {std::vector<float> m(matrix.size()); return m;};
    std::vector<float> adjustedGmeasure() {std::vector<float> m(matrix.size()); return m;};
    std::vector<float> positiveLR() {std::vector<float> m(matrix.size()); return m;};
    std::vector<float> negativeLR() {std::vector<float> m(matrix.size()); return m;};
    std::vector<float> youdenIndex() {
        std::vector<float> yi(matrix.size());

        std::vector<float> sp(matrix.size());
        sp = this -> specificity();
        std::vector<float> rec(matrix.size());
        rec = this->recall();
        for (int i  = 0; i < matrix.size(); i++) {
            yi[i] = rec[i] + sp[i] - 1;
        }
        return yi;
    };

    std::vector<float> balanceError() {
        std::vector<float> be(matrix.size());
        std::vector<float> bcr(matrix.size());
        bcr = this -> balancedClassificationRate();
        for (int i  = 0; i < matrix.size(); i++) {
            be[i] = 1 - bcr[i];
        }
        return be;
    };

    std::vector<float> recall(){
        std::vector<float> m(matrix.size());
        for (int i = 0; i < matrix.size(); i++){
            m[i] = (((float)TP[i]) / ((float)TP[i] + (float)FN[i]));
        }
        return m;
    };

    std::vector<float> precision(){
        std::vector<float> m(matrix.size());
        for (int i = 0; i < matrix.size(); i++){
            m[i] = ((float)TP[i])/((float)TP[i]+(float)FP[i]);
        }
        return m;
    };

    std::vector<float> Fmeasure(){
        std::vector<float> m(matrix.size());
        for (int i = 0; i <matrix.size(); i++){
            m[i] = (2*(float)TP[i])/(2*(float)TP[i] + (float)FP[i] + (float)FN[i]);
        }
        return m;
    };

    float macroPrecision() {
        float total = 0.0;
        std::vector<float> pr(matrix.size());
        pr = this->precision();
        for (int i=0; i<matrix.size(); i++){
            total += pr[i];
        }
        return total/matrix.size();
    }

    float macroRecall() {
        float total = 0.0;
        std::vector<float> rec(matrix.size());
        rec = this->recall();
        for (int i =0; i < matrix.size(); i++){
            total+= rec[i];
        }
        return total/matrix.size();
    }

    float macroF1Score() {
        float total =0.0;
        std::vector<float> f(matrix.size());
        f = this->Fmeasure();
        for (int z =0; z < matrix.size(); z++){
            total += f[z];
        }
        return total/matrix.size();
    }

    float weightedPrecision() {
        float num = 0.0;
        std::vector<float> pr(matrix.size());
        pr = this->precision();
        for (int i =0; i< matrix.size(); i++){
            num += weights[i] * pr[i];
        }
        if (totalInstances!=0){return num/(float)totalInstances;}
        else {return 0.0;}

    }

    float weightedRecall(){
        float num = 0.0;
        std::vector<float> rec(matrix.size());
        rec = this->recall();
        for (int i =0; i< matrix.size(); i++){
            num += weights[i] * rec[i];
        }
        if (totalInstances!=0){return num/(float)totalInstances;}
        else {return 0.0;}
    }

    float weightedF1(){
        float total = 0.0;
        float num = 0.0;
        std::vector<float> f(matrix.size());
        f = this->Fmeasure();
        for (int i =0; i< matrix.size(); i++){
            num += weights[i] * f[i];
        }
        if (totalInstances!=0){return num/(float)totalInstances;}
        else {return 0.0;}
    }

    float microF1Score(){
        float total = 0.0;
        for (int i =0; i < matrix.size(); i++){
            for (int j = 0; j < matrix.size(); j++){
                if (i == j){total += matrix[i][j];}
            }
        }
        return total/(float) totalInstances;
    }

    float kappa(){
        float TPs = 0.0;
        for (int i=0; i < matrix.size();i++){
            TPs += matrix[i][i];
        }
        float agree = TPs / (float) totalInstances;
        float chanceAgree =0.0;
        float agreePerLabel;
        for (int j = 0; j <matrix.size(); j++){
            float probA =0;
            float probB=0;
            for (int k = 0; k < matrix.size(); k++){
                probA += matrix[k][j];
                probB += matrix[j][k];
            }
            agreePerLabel = (probA/(float) totalInstances) * (probB/(float) totalInstances);
            chanceAgree += agreePerLabel;
        }

        float kappa = (agree - chanceAgree)/(1-chanceAgree);
        return kappa;
    }

    std::vector<float> DOR(){
        std::vector<float> m(3);
        for ( int i = 0; i < m.size(); i++){
            m[i] = ((float)TP[i]*(float)TN[i])/((float)FP[i]*(float)FN[i]);
        }
        return m;
    }

    std::vector<float> FPrate(){
        std::vector<float> m(matrix.size());
        for (int i = 0; i < matrix.size(); i++){
            m[i] = ((float)FP[i]) / ((float)TN[i] + (float)FP[i]);
        }
        return m;
    };

    std::vector<float> specificity(){
        std::vector<float> m(matrix.size());
        for (int i = 0; i < matrix.size(); i++){
            m = this->FPrate();
            m[i] = 1 - m[i];
        }
        return m;
    };

};


#endif //CLASSMETRICS_MARYCLASSIFICATION_H
