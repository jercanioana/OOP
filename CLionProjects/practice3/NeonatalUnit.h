//
// Created by Ioana Jercan on 2019-05-07.
//

#ifndef PRACTICE3_NEONATALUNIT_H
#define PRACTICE3_NEONATALUNIT_H

#include "HospitalDepartment.h"

class NeonatalUnit:  public HospitalDepartment{
private:
    int numberOfMothers;
    int numberOfNewborns;
public:
    NeonatalUnit();
    NeonatalUnit(const std::string& newHospitalName, int newNumberOfDoctors, int newNumberOfMothers, int newNumberOfNewborns);
    double averageGrade;
    bool isEfficient() override;
    std::string toString() override;
    ~NeonatalUnit();


};


#endif //PRACTICE3_NEONATALUNIT_H
