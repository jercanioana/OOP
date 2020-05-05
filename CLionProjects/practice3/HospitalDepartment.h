//
// Created by Ioana Jercan on 2019-05-07.
//

#ifndef PRACTICE3_HOSPITALDEPARTMENT_H
#define PRACTICE3_HOSPITALDEPARTMENT_H
#include <iostream>
#include <string>

class HospitalDepartment {
protected:
    std::string hospitalName;
    int numberOfDoctors;
public:
    HospitalDepartment();
    HospitalDepartment(const std::string& newHospitalName, int newNumberOfDoctors);
    virtual bool isEfficient();
    virtual std::string toString();
    ~HospitalDepartment();

};


#endif //PRACTICE3_HOSPITALDEPARTMENT_H
