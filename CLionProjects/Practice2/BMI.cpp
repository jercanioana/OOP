//
// Created by Ioana Jercan on 2019-05-04.
//

#include "BMI.h"
#include <string>
BMI::BMI() {

}

BMI::BMI(double value): value{value}{

}

bool BMI::isResultOK() {
    if(18.5 <= this->value && this->value <= 25)
        return true;
    return false;
}

std::string BMI::toString() const {
    return atoi(this->value);
}
