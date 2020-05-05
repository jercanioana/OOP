//
// Created by Ioana Jercan on 2019-04-10.
//

#ifndef ASSIGNMENT5_VALIDATOR_H
#define ASSIGNMENT5_VALIDATOR_H

#include "Chore.h"

class Validator{
public:
    static bool ValidateChore(const std::string& title, const std::string& type, const std::string& lastPerformed, const int& timesPerformed, const std::string& vision);
    static bool ValidateTitle(const std::string& title);
    static bool ValidateType(const std::string& type);
    static bool ValidateLastPerformed(const std::string& lastPerformed);
    static bool ValidateTimesPerformed(int timesPerformed);
    static bool ValidateVision(const std::string& vision);
};

class ValidatorException {
private:
    std::string message;
public:
    ValidatorException(const std:: string& message) : message(std::move(message)) {};
    std::string GetMessage() const{
        return this->message;
    }

};


#endif //ASSIGNMENT5_VALIDATOR_H
