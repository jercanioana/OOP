//
// Created by Ioana Jercan on 2019-05-08.
//

#ifndef TESTOOP2_DWELLING_H
#define TESTOOP2_DWELLING_H

#include <iostream>

class Dwelling {
private:
    std::string type;
    double price;
    bool isProfitable;
public:
    Dwelling();
    Dwelling(const std::string& newtype, double newprice, bool newisProfitable);
    bool IsIt() {return this->isProfitable;}
    std::string GetType() {return this->type;}
    double GetPrice() {return this->price;}
    double normalBankRate();
    double largeBankRate();
    ~Dwelling();

};


#endif //TESTOOP2_DWELLING_H
