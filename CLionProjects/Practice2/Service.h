//
// Created by Ioana Jercan on 2019-05-04.
//

#ifndef PRACTICE2_SERVICE_H
#define PRACTICE2_SERVICE_H

#include "Person.h"

class Service {
private:
    Person person;
public:
    explicit Service(Person& person): person(person) {}
    void AddBP(int systolicValue, int diastolicValue, const std::string& date);
    void AddBMI(double value, const std::string& date);
    ~Service() {};
};


#endif //PRACTICE2_SERVICE_H
