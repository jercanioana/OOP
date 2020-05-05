//
// Created by Ioana Jercan on 2019-05-07.
//

#include "HospitalDepartment.h"
HospitalDepartment::HospitalDepartment() : hospitalName{""}, numberOfDoctors{}{

}

HospitalDepartment::HospitalDepartment(const std::string &newHospitalName, int newNumberOfDoctors): hospitalName{newHospitalName}, numberOfDoctors{newNumberOfDoctors} {

}

std::string HospitalDepartment::toString() {
    return std::string();
}

bool HospitalDepartment::isEfficient() {
    return false;
}

HospitalDepartment::~HospitalDepartment() {

}