//
// Created by Ioana Jercan on 2019-05-08.
//

#ifndef TESTOOP2_NORMALCLIENT_H
#define TESTOOP2_NORMALCLIENT_H

#include "Client.h"

class NormalClient: public Client {
public:
    NormalClient();
    NormalClient(const std::string& newname, double newsalary);
    double totalIncome() override;
    bool isInterested(Dwelling& dwelling) override;
    std::string toString() override;
    ~NormalClient();
};


#endif //TESTOOP2_NORMALCLIENT_H
