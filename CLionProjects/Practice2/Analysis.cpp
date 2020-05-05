//
// Created by Ioana Jercan on 2019-05-04.
//

#include "Analysis.h"


Analysis::Analysis(std::string newDate) : date{newDate}{

}

bool Analysis::isResultOK() {
    if(BMI::isResultOK() == true)
        return true;
    return false;
}

std::string Analysis::toString() {
    return this->date;
}

Analysis::~Analysis() {

}
