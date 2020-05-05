//
// Created by Ioana Jercan on 2019-05-04.
//

#ifndef PRACTICE2_ANALYSIS_H
#define PRACTICE2_ANALYSIS_H
#include <iostream>
#include "BPI.h"
#include "BMI.h"

class Analysis: public BMI{
protected:
    std::string date;
public:

    Analysis(std::string newDate);
    bool isResultOK() override ;
    virtual std::string toString();
    ~Analysis();
};


#endif //PRACTICE2_ANALYSIS_H
