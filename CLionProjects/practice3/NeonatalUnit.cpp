//
// Created by Ioana Jercan on 2019-05-07.
//

#include "NeonatalUnit.h"

NeonatalUnit::NeonatalUnit(): numberOfMothers{}, numberOfNewborns{} {

}

NeonatalUnit::NeonatalUnit(const std::string& newHospitalName, int newNumberOfDoctors, int newNumberOfMothers, int newNumberOfNewborns): HospitalDepartment(newHospitalName, newNumberOfDoctors), numberOfMothers{newNumberOfMothers} ,numberOfNewborns{newNumberOfNewborns} {

}

bool NeonatalUnit::isEfficient() {
    if(this->averageGrade > 8.5 && this->numberOfNewborns >= this->numberOfMothers)
        return true;
    return false;
}

std::string NeonatalUnit::toString() {
    std::string hosp, nrdocs, nrmoms, nrnewborns, avg;
    hosp = this->hospitalName;
    nrdocs = std::to_string(this->numberOfDoctors);
    nrmoms = std::to_string(this->numberOfMothers);
    nrnewborns = std::to_string(this->numberOfNewborns);
    avg = std::to_string(this->averageGrade);
    return hosp + ", " + nrdocs + ", " + nrnewborns + ", " + nrmoms +", "+ avg;

}

NeonatalUnit::~NeonatalUnit() {

}