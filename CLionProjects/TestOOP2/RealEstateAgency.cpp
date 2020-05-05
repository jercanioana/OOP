//
// Created by Ioana Jercan on 2019-05-08.
//

#include "RealEstateAgency.h"
#include <algorithm>
RealEstateAgency::RealEstateAgency() {

}

void RealEstateAgency::addDwelling(const std::string& type, double price, bool isProfitable) {
    Dwelling dwelling = Dwelling{type, price, isProfitable};
    this->dwellings.push_back(dwelling);
}

void RealEstateAgency::addClient(Client *client) {
    this->clients.push_back(client);
}

void RealEstateAgency::RemoveClient(const std::string &name) {
    int position = 0;
    for(int index = 0; index <= this->clients.size(); index++){
        if (this->clients[index]->GetName() == name) {
            position = index;
            break;
        }
    }

    this->clients.erase(this->clients.begin()+position);
}

RealEstateAgency::~RealEstateAgency() {

}