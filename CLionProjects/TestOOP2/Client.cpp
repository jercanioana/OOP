//
// Created by Ioana Jercan on 2019-05-08.
//

#include "Client.h"
Client::Client() : name{""}, salary{}
{

}

Client::Client(const std::string &newname, double newsalary): name{newname}, salary{newsalary} {

}


double Client::totalIncome() {
    return this->salary;
}

bool Client::isInterested(Dwelling &dwelling) {
    return false;

}

std::string Client::toString() {
    return std::string();
}

Client::~Client() {

}