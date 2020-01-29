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

    float misclassification(){return 0.0;};
    float prevalence(){ return 0.0;};

    std::vector<float> Gmeasure(){std::vector<float> m(matrix.size()); return m;};
    float jaccardCoeff(){return 0.0;};
    float matthewsCoeff(){return 0.0;}
    std::vector<float> discriminantPower(){std::vector<float> m(matrix.size()); return m;}
    std::vector<float> markedness(){std::vector<float> m(matrix.size()); return m;}
    std::vector<float> balancedClassificationRate(){std::vector<float> m(matrix.size()); return m;}
    std::vector<float> geometricMean(){std::vector<float> m(matrix.size()); return m;}
    std::vector<float> optPrecision(){std::vector<float> m(matrix.size()); return m;}
    std::vector<float> NPV(){std::vector<float> m(matrix.size()); return m;}
    float hamming() {return 0.0;}
    float subset01() {return 0.0;}
    float falseNegativeRate() {return 0.0;};
    std::vector<float> adjustedFmeasure() {std::vector<float> m(matrix.size()); return m;};
    std::vector<float> adjustedGmeasure() {std::vector<float> m(matrix.size()); return m;};
    std::vector<float> positiveLR() {std::vector<float> m(matrix.size()); return m;};
    std::vector<float> negativeLR() {std::vector<float> m(matrix.size()); return m;};
    std::vector<float> youdenIndex() {std::vector<float> m(matrix.size()); return m;};
    std::vector<float> balanceError() {std::vector<float> m(matrix.size()); return m;};

    //position is label number
//    float precisionMultiClass (int pos){
//        int total= 0;
//        for (int f = 0; f <matrix.size(); f++ ){
//            total = total + matrix[pos-1][f];
//        }
//        if (total!=0){
//            float m = matrix[pos-1][pos-1]/(float) total;
//            return m*100;
//        }
//        else {
//            return 0.0;
//        }
//    };

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

//    float recallMultiClass(int pos){
//        int total = 0;
//        for (int y=0; y< matrix.size(); y++){
//            total = total+ matrix[y][pos-1];
//        };
//        if (total!=0){
//            float m = matrix[pos-1][pos-1]/(float) total;
//            return m*100;
//        }
//        else {
//            return 0.0;
//        }
//    }

//    float F1ScoreMultiClass(int pos) {
//        float total = 0.0;
//        total= this->precisionMultiClass(pos) +this->recallMultiClass(pos);
//        float numerator = 2 * this->precisionMultiClass(pos) * this->recallMultiClass(pos);
//        if (total!=0.0){return numerator/total;}
//        else{return 0.0;}
//    }

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
