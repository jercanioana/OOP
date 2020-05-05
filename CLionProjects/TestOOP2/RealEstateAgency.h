//
// Created by Ioana Jercan on 2019-05-08.
//

#ifndef TESTOOP2_REALESTATEAGENCY_H
#define TESTOOP2_REALESTATEAGENCY_H

#include "Client.h"
#include "NormalClient.h"
#include "WealthyClient.h"
#include <vector>
class RealEstateAgency {
private:
    std::vector<Client*> clients;
    std::vector<Dwelling> dwellings;
public:
    RealEstateAgency();
    void addDwelling(const std::string& type, double price, bool isProfitable);
    void addClient(Client* client);
    void RemoveClient(const std::string& name);
    std::vector<Client*> GetClients() { return clients;}
    std::vector<Dwelling> GetDwellings() { return dwellings; }
    ~RealEstateAgency();
};


#endif //TESTOOP2_REALESTATEAGENCY_H
