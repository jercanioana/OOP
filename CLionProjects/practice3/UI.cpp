//
// Created by Ioana Jercan on 2019-05-07.
//

#include "UI.h"

void UI::Add() {
    std::string type, hospitalName;
    int nrdocs, nrbabies, nrmoms, nrpatients;
    double avg;
    std::cout<<"Enter nr of doctors: ";
    std::cin>>nrdocs;
    std::cout<<"Enter the type: ";
    getline(std::cin, type);
    if(type == "surgery"){
        std::cout<<"Enter nr of patients: ";
        std::cin>>nrpatients;
        HospitalDepartment* surgery = new Surgery{"H", nrdocs, nrpatients};
        this->controller.AddDepartment(surgery);
    }
    else{
        std::cout<<"Enter babies: ";
        std::cin>>nrbabies;
        std::cout<<"Enter moms: ";
        std::cin>>nrmoms;
        std::cout<<"Enter avg: ";
        std::cin>>avg;
        HospitalDepartment* neonatalUnit = new NeonatalUnit{"H", nrdocs, nrmoms, nrbabies};
        this->controller.AddDepartment(neonatalUnit);
    }

}

void UI::List() {
    std::vector<HospitalDepartment*> dep = this->controller.GetAllDepartments();
    for(auto &i: dep)
        std::cout<<i->toString()<<"\n";
}

void UI::ListEff() {
    std::vector<HospitalDepartment*> dep = this->controller.GetAllEfficientDepartments();
    for(auto &i: dep)
        std::cout<<i->toString()<<"\n";

}

void UI::RunMenu() {
    int command;
    HospitalDepartment* d = new Surgery{"H", 19, 19};
    controller.AddDepartment(d);
    while(1){
        std::cout<<"Enter a command: ";
        std::cin>>command;
        if(command == 0)
            break;
        if(command == 1)
            this->Add();
        if(command == 2)
            this->List();
        if(command == 3)
            this->ListEff();
    }
}

UI::~UI() {

}