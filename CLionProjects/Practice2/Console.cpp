//
// Created by Ioana Jercan on 2019-05-04.
//

#include "Console.h"
void Console::Add() {
    std::string type;
    std::string date;
    double value;
    int s, d;
    std::cout<<"Enter the type of analysis: "<<"\n";
    std::cin.get();
    std::getline(std::cin, type);
    std::cout<<"Enter the date: "<<"\n";
    std::cin.get();
    std::getline(std::cin, date);
    if(type == "BMI") {
        std::cin.get();
        std::cin>>value;
        this->service.AddBMI(value, date);
    }
    if(type == "BP"){
        std::cin.get();
        std::cin>>s;
        std::cin.get();
        std::cin>>d;
        this->service.AddBP(s, d, date);
    }

}

void Console::RunMenu() {
    int command;
    std::cout<<"Enter a command: "<<"\n";
    std::cin>>command;
    while(1){
        if(command == 0)
            break;
        if(command == 1)
            this->Add();
    }
}
Console::~Console() {

}