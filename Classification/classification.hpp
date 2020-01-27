#ifndef classification_hpp
#define classification_hpp
#include <stdio.h>
#include <math.h>
#include <map>

#endif

#include "InputVectors/input.hpp"
#include <vector>
#include <iostream>

enum ClassificationType {
    BINARY, MARY, MULTILABEL
};

class Classification {

public:
    Classification(InputVectors input){
        i = input;

    };
    InputVectors i;

    virtual float accuracy() = 0;
    virtual float misclassification() = 0;
    virtual float precision() = 0;
    virtual float recall() = 0;
    virtual float FPrate() = 0;
    virtual float specificity() = 0;
    virtual float prevalence() = 0;
    virtual float Fmeasure() = 0;
    virtual float Gmeasure() = 0;
    virtual float precisionMultiClass(int pos) = 0;
    virtual float recallMultiClass(int pos) = 0;
    virtual float F1ScoreMultiClass(int pos) = 0;
    virtual float macroPrecision() = 0;
    virtual float macroRecall() = 0;
    virtual float macroF1Score() =0;
    virtual float weightedF1() = 0;
    virtual float weightedRecall() =0;
    virtual float weightedPrecision() =0;
    virtual std::vector<int> getWeights()=0;
    virtual float microF1Score() = 0;
    virtual float jaccardCoeff() = 0;
    virtual float matthewsCoeff() = 0;
    virtual float discriminantPower()=0;
    virtual float markedness()=0;
    virtual float balancedClassificationRate() = 0;
    virtual float geometricMean() = 0;
    virtual float optPrecision() = 0;
    virtual float NPV() = 0;
    virtual float hamming() = 0;
    virtual float subset01() = 0;
    virtual float kappa() = 0;
    virtual float falseNegativeRate() = 0;
    virtual float adjustedFmeasure() = 0;
    virtual float adjustedGmeasure() = 0;
    virtual float positiveLR() = 0;
    virtual float negativeLR() = 0;
    virtual float youdenIndex() = 0;
    virtual float balanceError() = 0;


    std::map<std::string, float> getAllMetrics();

};

class BinaryClassification : public Classification {

public:
    BinaryClassification(InputVectors input) : Classification(input){
        matrix = i.getConfustionMatrix();
        TP =(float) matrix[0][0];
        TN =(float) matrix[1][1];
        FP =(float) matrix[0][1];
        FN =(float) matrix[1][0];
        instances = TP + TN + FP + FN;


    }
    float TP;
    float TN;
    float FP;
    float FN;
    std::vector<std::vector<int>>  matrix;
    float instances;

    float accuracy(){

        float m = (TP + TN) / instances;
        return m;
    };

    float misclassification(){
        float m = 1- ((TP + TN) / instances);
        return m;
    };
    //PPV
    float precision(){
        float m = (TP) / (TP + FP);
        return m;
    };
    //TPR or sensitivity or hit rate
    float recall(){
        float m = ((TP) / (TP + FN));
        return m;
    };
    float FPrate(){
        float m = (FP) / (TN + FP);
        return m;
    };
    //TNR or inverse recall
    float specificity(){
        float m = 1-this->FPrate();
        return m;
    };
    float prevalence(){
        float m = (FN + TP) / (instances);
        return m;
    };
    float Fmeasure(){
        float m = (2*this->recall()*this->precision())/(this->recall()+this->precision());
        return m;
    };
    float Gmeasure(){
        float num = this->recall() * this->precision();
        float m = sqrt(num);
        return m;
    };

    float jaccardCoeff(){
        float m;
        m = TP/(TP + FP + FN);
        return m ;
    }
    //A coefficient of 1 indicates a perfect prediction,
    //-1 represents total disagreement between prediction and true
    float matthewsCoeff(){
        float num = (TP*TN) - (FP*FN);
        float denum= sqrt((TP+FP)*(TP+FN)*(TN+FP)*(TN+FN));
        return num/denum;
    }

    float NPV(){
        float n = TN/(FN+TN);
        return n;
    }

    float discriminantPower(){
        float coeff = sqrt(3)/M_PI;
        float dp = log10((this->recall())/(1-(this->specificity()))) + log10((this->specificity())/(1-(this->recall())));
        return coeff*dp;
    }

    float markedness(){
        float m = (this->precision()) + (this->NPV()) - 1;
        return m;
    }

    float balancedClassificationRate(){
        float b = ((this->recall())+(this->specificity()))/2;
        return b;
    };

    float geometricMean(){
        float sq = sqrt((this->recall())*(this->specificity()));
        return sq;

    };

    float optPrecision(){
        float opt = (this->accuracy()) - ( abs((this->recall())-(this->specificity())) / ((this->recall())+(this->specificity())) );
        return opt;
    };

    float kappa() {
        float agree = (TP + TN) /instances;
        float chanceAgree1 = ((TP + FN)/ instances) * ((TP + FP)/instances);
        float chanceAgree2 = ((TP + FP)/instances) * ((FP + TN)/instances);
        float chanceAgree = chanceAgree1 + chanceAgree2;
        float m = (agree - chanceAgree)/(1- chanceAgree);

        return m;
    }

    float falseNegativeRate(){
        float m = FN /(FP + TN);
        return m;
    };

    float adjustedFmeasure() {
//        returning f2 score and not agf
        float agf;
        float invPrecision = TN/(TN + FN);
        float invRecall = TN/(TN + FP);
        float invF = ((1.25)*(invPrecision*invRecall)) / (0.25*invPrecision + invRecall);
        float f2 = (5*TP) / (5*TP + 4*FN + FP);
        agf = sqrt(f2 * invF);
        return agf;
    };

    float adjustedGmeasure() {

        if (this->recall() == 0.0) {
            return 0.0;
        }
        else {
            float agm = (this->geometricMean() + this->specificity()*(FP + TN)) / (1 + FP + TN);
            return agm;
        }
    };

    float positiveLR() {
        float m = (this->recall()) / (1 - this->specificity());
        return m;
    };

    float negativeLR() {
        float m = (1 - this->recall()) / (this->specificity());
        return m;
    };

    float youdenIndex() {
        float m = this->recall() + this->specificity() - 1;
        return m;
    };

    float balanceError() {
        float m = 1 - this->balancedClassificationRate();
        return m;
    };

    float precisionMultiClass (int pos){return 0.0;}
    float recallMultiClass (int pos) {return 0.0;}
    float F1ScoreMultiClass(int pos) {return 0.0;}
    float macroPrecision() {return 0.0;}
    float macroRecall() {return 0.0;}
    float macroF1Score() {return 0.0;}
    float weightedPrecision() {return 0.0;};
    float weightedRecall(){return 0.0;};
    float weightedF1(){return 0.0;}

    std::vector<int> getWeights(){
        std::vector<int> mo;
        return mo;
    }
    float microF1Score() {return 0.0;}
    virtual float hamming() {return 0.0;}
    virtual float subset01() {return 0.0;}
};

class MaryClassification : public Classification {
public:
    MaryClassification (InputVectors input) : Classification(input){
        matrix = i.getConfustionMatrix();
        totalInstances =0;
        weights.resize(matrix.size());
        for (int h = 0; h < matrix.size(); h++){
            for (int k = 0; k < matrix[0].size(); k++){
                totalInstances += matrix[h][k];
                weights[k] += matrix[h][k];
            }
        }
//        for (int i =0; i< matrix.size(); i++){
//
//        }



    }
    std::vector<std::vector<int>> matrix;
    int totalInstances;
    //1D vector with instances per class from GT
    std::vector<int> weights;

    std::vector<int> getWeights(){
        return weights;
    }

    float accuracy(){return 0.0;};
    float misclassification(){return 0.0;};
    float precision(){return 0.0;};
    float recall(){return 0.0;};
    float FPrate(){return 0.0;};
    float specificity(){return 0.0;};
    float prevalence(){return 0.0;};
    float Fmeasure(){return 0.0;};
    float Gmeasure(){return 0.0;};
    float jaccardCoeff(){return 0.0;};
    float matthewsCoeff(){return 0.0;}
    float discriminantPower(){return 0.0;}
    float markedness(){return 0.0;}
    float balancedClassificationRate(){return 0.0;}
    float geometricMean(){return 0.0;}
    float optPrecision(){return 0.0;}
    float NPV(){return 0.0;}
    float hamming() {return 0.0;}
    float subset01() {return 0.0;}
    float falseNegativeRate() {return 0.0;};
    float adjustedFmeasure() {return 0.0;};
    float adjustedGmeasure() {return 0.0;};
    float positiveLR() {return 0.0;};
    float negativeLR() {return 0.0;};
    float youdenIndex() {return 0.0;};
    float balanceError() {return 0.0;};

    //position is label number
    float precisionMultiClass (int pos){
        int total= 0;
        for (int f = 0; f <matrix.size(); f++ ){
            total = total + matrix[pos-1][f];
        }
        if (total!=0){
            float m = matrix[pos-1][pos-1]/(float) total;
            return m*100;
        }
        else {
            return 0.0;
        }
    };

    float recallMultiClass(int pos){
        int total = 0;
        for (int y=0; y< matrix.size(); y++){
            total = total+ matrix[y][pos-1];
        };
        if (total!=0){
            float m = matrix[pos-1][pos-1]/(float) total;
            return m*100;
        }
        else {
            return 0.0;
        }
    }

    float F1ScoreMultiClass(int pos) {
        float total = 0.0;
        total= this->precisionMultiClass(pos) +this->recallMultiClass(pos);
        float numerator = 2 * this->precisionMultiClass(pos) * this->recallMultiClass(pos);
        if (total!=0.0){return numerator/total;}
        else{return 0.0;}
    }

    float macroPrecision() {
        float total = 0.0;
        for (int i=1; i<=matrix.size(); i++){
            total += this->precisionMultiClass(i);
        }
        return total/matrix.size();
    }

    float macroRecall() {
        float total = 0.0;
        for (int i =1; i <= matrix.size(); i++){
            total+= this->recallMultiClass(i);
        }
        return total/matrix.size();
    }

    float macroF1Score() {
        float total =0.0;
        for (int zz =1; zz <= matrix.size(); zz++){
            total += this->F1ScoreMultiClass(zz);
        }
        return total/matrix.size();
    }

    float weightedPrecision() {
        float total = 0.0;
        float num = 0.0;
        for (int i =0; i< matrix.size(); i++){
            total += weights[i];
            num += weights[i] * this->precisionMultiClass(i+1);
        }
        if (total!=0){return num/total;}
        else {return 0.0;}

    }

    float weightedRecall(){
        float total = 0.0;
        float num = 0.0;
        for (int i =0; i< matrix.size(); i++){
            total += weights[i];
            num += weights[i] * this->recallMultiClass(i+1);
        }
        if (total!=0){return num/total;}
        else {return 0.0;}
    }

    float weightedF1(){
        float total = 0.0;
        float num = 0.0;
        for (int i =0; i< matrix.size(); i++){
            total += weights[i];
            num += weights[i] * this->F1ScoreMultiClass(i+1);
        }
        if (total!=0){return num/total;}
        else {return 0.0;}
    }

    float microF1Score(){
        float total = 0.0;
        for (int i =0; i < matrix.size(); i++){
            for (int j = 0; j < matrix.size(); j++){
                if (i == j){total += matrix[i][j];}
            }
        }
        return total/(float) totalInstances*100;
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


};

class MultiLabelClassification : public Classification {
    public:
        MultiLabelClassification (InputVectors i): Classification (i) {
            groundTruth  = i.getGroundTruth();
            predictedInput = i.getPredicted();
        }

        std::vector<std::vector<int>> groundTruth;
        std::vector<std::vector<int>> predictedInput;

    virtual float hamming() {
        float num = 0;
        float denum = groundTruth.size()* groundTruth[0].size();
        for (int i = 0; i < groundTruth.size(); i++) {
            for (int j = 0; j < groundTruth[0].size(); j++) {
                if (groundTruth[i][j] != predictedInput[i][j]){num +=1;}
            }
        }
        return num/denum;
    }

    virtual float subset01() {
        float num = 0;
        float denum = groundTruth.size();
        for (int i = 0; i < groundTruth.size(); i++) {
            if (groundTruth[i] != predictedInput[i]) { num += 1; }
        }
        return num/denum;
    };

    float accuracy() {return 0.0;}
    float misclassification() {return 0.0;}
    float precision() {return 0.0;}
    float recall() {return 0.0;}
    float FPrate() {return 0.0;}
    float specificity() {return 0.0;}
    float prevalence() {return 0.0;}
    float Fmeasure() {return 0.0;}
    float Gmeasure() {return 0.0;}
    float precisionMultiClass(int pos) {return 0.0;}
    float recallMultiClass(int pos) {return 0.0;}
    float F1ScoreMultiClass(int pos) {return 0.0;}
    float macroPrecision() {return 0.0;}
    float macroRecall() {return 0.0;}
    float macroF1Score() {return 0.0;}
    float weightedF1() {return 0.0;}
    float weightedRecall() {return 0.0;}
    float weightedPrecision() {return 0.0;}
    std::vector<int> getWeights(){
        std::vector<int> mo;
        return mo;
    }
    float microF1Score() {return 0.0;}
    float jaccardCoeff() {return 0.0;}
    float matthewsCoeff() {return 0.0;}
    float discriminantPower(){return 0.0;}
    float markedness(){return 0.0;}
    float balancedClassificationRate() {return 0.0;}
    float geometricMean() {return 0.0;}
    float optPrecision() {return 0.0;}
    float NPV(){return 0.0;}
    float kappa() {return 0.0;}
    float falseNegativeRate() {return 0.0;};
    float adjustedFmeasure() {return 0.0;};
    float adjustedGmeasure() {return 0.0;};
    float positiveLR() {return 0.0;};
    float negativeLR() {return 0.0;};
    float youdenIndex() {return 0.0;};
    float balanceError() {return 0.0;};

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
