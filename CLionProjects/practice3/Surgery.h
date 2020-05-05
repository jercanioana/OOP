//
// Created by Ioana Jercan on 2019-05-07.
//

#ifndef PRACTICE3_SURGERY_H
#define PRACTICE3_SURGERY_H
#include "HospitalDepartment.h"

class Surgery: public HospitalDepartment {
private:
    int numberOfPatients;
public:
    Surgery();
    Surgery(const std::string& newHospitalName, int newNumberOfDoctors, int newNumberOfPatients);
    bool isEfficient() override;
    std::string toString() override;
    ~Surgery();

};


#endif //PRACTICE3_SURGERY_H
