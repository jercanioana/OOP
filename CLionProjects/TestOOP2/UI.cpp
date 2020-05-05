//
// Created by Ioana Jercan on 2019-05-08.
//

#include "UI.h"


void UI::Add() {
    std::string type;
    std::vector<Client*> isInt;
    double price;
    bool isProfitable;
    std::cout<<"Enter a type: ";
    std::cin>>type;
    std::cout<<"Enter a price: ";
    std::cin>>price;
    std::cout<<"Is it profitable: ";
    std::cin>>isProfitable;
    this->realEstateAgency.addDwelling(type, price, isProfitable);
    Dwelling d = Dwelling{type, price, isProfitable};
    std::vector<Client*> c = this->realEstateAgency.GetClients();
    for(auto &i: c){
        if(i->isInterested(d))
            isInt.push_back(i);
    }
    for(auto &i: isInt)
    {
        std::cout<<i->toString()<<"\n";
    }
}
void UI::Remove() {
    std::string name;
    std::cout<<"Enter a name: ";
    std::cin>>name;
    this->realEstateAgency.RemoveClient(name);
}
void UI::ListDwellings() {
    std::vector<Dwelling> d = this->realEstateAgency.GetDwellings();
    for(auto &i: d){
        std::cout<<i.GetType()<<" "<<i.GetPrice()<<" "<<i.IsIt()<<"\n";
    }
}
void UI::ListClients() {
    std::vector<Client*> c = this->realEstateAgency.GetClients();
    for(auto &i: c){
        std::cout<<i->toString()<<"\n";
    }

}
void UI::RunMenu() {
    int command;
    Client* c;
    c = new NormalClient{"Ana", 100};
    Client* d;
    d = new NormalClient{"N", 10};
    this->realEstateAgency.addClient(c);
    this->realEstateAgency.addClient(d);
    while(1){
        std::cout<<"Enter a command: ";
        std::cin>>command;
        if(command == 0)
            break;
        if(command == 1)
            this->Add();
        if(command == 2)
            this->ListClients();
        if(command == 3)
            this->ListDwellings();
        if(command == 4)
            this->Remove();
    }
}
UI::~UI() {

}