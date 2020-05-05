//
// Created by Ioana Jercan on 2019-05-08.
//

#ifndef TESTOOP2_UI_H
#define TESTOOP2_UI_H

#include "RealEstateAgency.h"
class UI {
private:
    RealEstateAgency& realEstateAgency;
public:
    UI();
    UI(RealEstateAgency& realEstateAgency1) : realEstateAgency{realEstateAgency1} {}
    void Add();
    void Remove();
    void ListClients();
    void ListDwellings();
    void RunMenu();
    ~UI();

};


#endif //TESTOOP2_UI_H
