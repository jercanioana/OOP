//
// Created by Ioana Jercan on 2019-05-04.
//

#ifndef PRACTICE2_BPI_H
#define PRACTICE2_BPI_H

#include "Analysis.h"

class BP{
private:
    int systolicValue;
    int diastolicValue;

public:
    BP() {};
    BP(int systolicValue, int diastolicValue);
    virtual bool isResultOK();
    //std::string toString();
    ~BP();

};


#endif //PRACTICE2_BPI_H
