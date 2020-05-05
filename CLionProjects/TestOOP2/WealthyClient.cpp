//
// Created by Ioana Jercan on 2019-05-08.
//

#include "WealthyClient.h"
WealthyClient::WealthyClient() {

}

WealthyClient::WealthyClient(const std::string &name, double salary, double moneyFromInvestments): Client{name, salary}, moneyFromInvestments{moneyFromInvestments} {

}
bool WealthyClient::isInterested(Dwelling &dwelling) {
    if(dwelling.largeBankRate() <= this->salary && dwelling.IsIt())
        return true;
    return false;
}

std::string WealthyClient::toString() {
    std::string money, totalIncome;
    money = std::to_string(moneyFromInvestments);
    totalIncome = std::to_string(salary);
    return this->name + ", " + money + ", " + totalIncome;
}

double WealthyClient::totalIncome() {
    return this->salary+this->moneyFromInvestments;
}
WealthyClient::~WealthyClient() {

}