//
// Created by Ioana Jercan on 2019-05-08.
//

#ifndef TESTOOP2_WEALTHYCLIENT_H
#define TESTOOP2_WEALTHYCLIENT_H

#include "Client.h"

class WealthyClient: public Client {
private:
    double moneyFromInvestments;
public:
    WealthyClient();
    WealthyClient(const std::string& name, double salary, double moneyFromInvestments);
    double totalIncome() override;
    std::string toString() override;
    bool isInterested(Dwelling& dwelling) override;
    ~WealthyClient();
};


#endif //TESTOOP2_WEALTHYCLIENT_H
