//
// Created by Ioana Jercan on 2019-05-08.
//

#include "Dwelling.h"
Dwelling::Dwelling(): type{""}, price{}, isProfitable{} {

}

Dwelling::Dwelling(const std::string &newtype, double newprice, bool newisProfitable): type{newtype}, price{newprice}, isProfitable{newisProfitable} {

}

double Dwelling::largeBankRate() {
    return this->price/100;
}

double Dwelling::normalBankRate() {
    return this->price/100;
}

Dwelling::~Dwelling() {

}