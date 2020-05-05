//
// Created by Ioana Jercan on 2019-05-08.
//

#include "NormalClient.h"
NormalClient::NormalClient(){

}

NormalClient::NormalClient(const std::string &newname, double newsalary): Client{newname, newsalary} {

}

double NormalClient::totalIncome() {
    return this->salary;
}
bool NormalClient::isInterested(Dwelling &dwelling) {
    if(dwelling.normalBankRate() <= this->salary)
        return true;
    return false;
}
std::string NormalClient::toString() {
    std::string sal;
    sal = std::to_string(this->salary);
    return this->name + ", " + sal;
}
NormalClient::~NormalClient() {

}