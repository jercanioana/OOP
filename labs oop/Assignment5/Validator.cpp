//
// Created by Ioana Jercan on 2019-04-10.
//

#include "Validator.h"
#include <iostream>
bool Validator::ValidateChore(const std::string &title, const std::string &type, const std::string &lastPerformed,
                              const int &timesPerformed, const std::string &vision) {
    try{
        Validator::ValidateTitle(title) && Validator::ValidateType(type) && Validator::ValidateLastPerformed(lastPerformed) && Validator::ValidateTimesPerformed(timesPerformed) && Validator::ValidateVision(vision);
    }
    catch(const ValidatorException& exception){
        std::cout<<exception.GetMessage()<<std::endl;
        return false;
    }
    return true;
}

bool Validator::ValidateTitle(const std::string &title) {
    if(title.empty()) {
        throw ValidatorException("Wrong input.");
    }
    return true;
}

bool Validator::ValidateType(const std::string &type) {
    if(type.empty()) {
        throw ValidatorException("Wrong input.");
    }
    return true;
}

bool Validator::ValidateTimesPerformed(int timesPerformed) {
    if(timesPerformed < 0)
    {
        throw ValidatorException("Wrong input.");
    }
    return true;
}

bool Validator::ValidateLastPerformed(const std::string &lastPerformed) {
    if(lastPerformed.empty()) {
        throw ValidatorException("Wrong input.");
    }
    return true;
}

bool Validator::ValidateVision(const std::string &vision) {
    if(vision.empty()) {
        throw ValidatorException("Wrong input.");
    }
    return true;
}