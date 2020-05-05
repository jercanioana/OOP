//
// Created by Ioana Jercan on 2019-05-07.
//

#include "Surgery.h"
Surgery::Surgery(): numberOfPatients{} {

}

Surgery::Surgery(const std::string& newHospitalName, int newNumberOfDoctors, int newNumberOfPatients): HospitalDepartment(newHospitalName, newNumberOfDoctors), numberOfPatients{newNumberOfPatients} {

}

std::string Surgery::toString() {
    std::string nrdocs, nrpats;
    nrdocs = std::to_string(this->numberOfDoctors);
    nrpats = std::to_string(this->numberOfPatients);
    return this->hospitalName+", " + nrdocs + ", " + nrpats;
}

bool Surgery::isEfficient() {
    if(this->numberOfPatients/this->numberOfDoctors >= 2)
        return true;
    return false;
}

Surgery::~Surgery() {

}