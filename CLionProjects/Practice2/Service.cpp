//
// Created by Ioana Jercan on 2019-05-04.
//

#include "Service.h"
void Service::AddBP(int systolicValue, int diastolicValue, const std::string& date) {
    BP bp{systolicValue, diastolicValue};
    Analysis analysis{date};
    this->person.addAnalysis(analysis);
}

void Service::AddBMI(double value, const std::string &date) {
    BMI bmi {value};
    Analysis analysis{date};
    this->person.addAnalysis(analysis);
}