//
// Created by Ioana Jercan on 2019-05-07.
//

#ifndef PRACTICE3_CONTROLLER_H
#define PRACTICE3_CONTROLLER_H

#include "HospitalDepartment.h"
#include <vector>

class Controller {
private:
    std::vector<HospitalDepartment*> departments;
public:
    Controller() = default;
    void AddDepartment(HospitalDepartment* d);
    std::vector<HospitalDepartment*> GetAllDepartments() {return departments;}
    std::vector<HospitalDepartment*> GetAllEfficientDepartments();
    void writeToFile(const std::string& fileName);
    ~Controller();
};


#endif //PRACTICE3_CONTROLLER_H
