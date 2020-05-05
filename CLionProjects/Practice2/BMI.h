//
// Created by Ioana Jercan on 2019-05-04.
//

#ifndef PRACTICE2_BMI_H
#define PRACTICE2_BMI_H

#include "Analysis.h"

class BMI{
private:
    double value;

public:
    BMI(double value);
    virtual bool isResultOK();
    std::string toString() const;
    ~BMI(){};
};


#endif //PRACTICE2_BMI_H
