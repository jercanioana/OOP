//
// Created by Ioana Jercan on 2019-05-04.
//

#include "BPI.h"
#include <sstream>


BP::BP(int systolicValue, int diastolicValue) : systolicValue{systolicValue}, diastolicValue{diastolicValue}
{

}

bool BP::isResultOK() {
    if(this->systolicValue >= 90 && this->systolicValue <= 119 && this->diastolicValue>=60 && this->diastolicValue<=79)
        return true;
    return false;
}

//std::string BP::toString() {
//    std::stringstream buffer;
//    buffer<<this->systolicValue<<" "<<this->diastolicValue<<"\n";
//    return buffer.str();
//}

BP::~BP() {

}