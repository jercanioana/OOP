//
// Created by Ioana Jercan on 2019-05-07.
//

#include "Controller.h"
#include <fstream>

void Controller::AddDepartment(HospitalDepartment* d) {
    this->departments.push_back(d);
    this->writeToFile("");
}

std::vector<HospitalDepartment*> Controller::GetAllEfficientDepartments() {
    std::vector<HospitalDepartment*> eff;
    for(auto &i: departments){
        if(i->isEfficient())
            eff.push_back(i);
    }
    return eff;
}

void Controller::writeToFile(const std::string& fileName) {
    std::ofstream output;
    output.open("file.txt");
    if(output.is_open()){
        for(auto &i: departments)
            output<<i->toString();
    }
    output.close();
}
Controller::~Controller() {

}