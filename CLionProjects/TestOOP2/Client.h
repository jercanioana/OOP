//
// Created by Ioana Jercan on 2019-05-08.
//

#ifndef TESTOOP2_CLIENT_H
#define TESTOOP2_CLIENT_H

#include "Dwelling.h"

class Client {
protected:
    std::string name;
    double salary;
public:
    Client();
    Client(const std::string& newname, double newsalary);
    virtual double totalIncome();
    std::string GetName(){
        return this->name;
    }
    virtual std::string toString();
    virtual bool isInterested(Dwelling& dwelling);
    ~Client();

};


#endif //TESTOOP2_CLIENT_H
