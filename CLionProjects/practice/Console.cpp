//
// Created by Ioana Jercan on 2019-04-08.
//

#include "Console.h"
void Console::list() {
    int size = this->service.size();
    DynamicVector<Team> teams = this->service.list();
    for (int index = 0; index < size; index++){
        std::cout<< teams[index].getName()<<" "<<teams[index].getCountry()<<" "<<teams[index].getScore()<<"\n";
    }
}

void Console::add() {
    std::string name, country;
    int score = 0;
    std::cout<<"Enter a name: \n";
    std::cin.get();
    std::getline(std::cin,name);
    std::cout<<"Enter a country: \n";
    std::getline(std::cin, country);

    this->service.add(name, country, score);
    std::cout<<"Team added. \n";
}

void Console::pair() {
    Team teamOne, teamTwo, winnerTeam;
    std::string nameOfFirstTeam;
    std::string nameOfSecondTeam;
    std::string nameOfWinningTeam;
    std::cout<<"Enter a name: \n";
    std::cin.get();
    std::getline(std::cin,nameOfFirstTeam);

    std::cout<<"Enter a name: \n";
    std::cin.get();
    std::getline(std::cin,nameOfSecondTeam);

    std::cout<<"Enter a name: \n";
    std::getline(std::cin,nameOfWinningTeam);
    winnerTeam = this->service.findByName(nameOfWinningTeam);
    teamOne = this->service.findByName(nameOfFirstTeam);
    teamTwo = this->service.findByName(nameOfSecondTeam);
    if(teamOne.getScore() == teamTwo.getScore()){
        if(teamOne.getName() == winnerTeam.getName()) {
            teamOne.setScore(teamOne.getScore() + 1);
            std::cout<<teamOne.getScore();
        }
        else if(strcmp(teamTwo.getName().c_str(), winnerTeam.getName().c_str()) == 0)
            teamTwo.setScore(teamTwo.getScore()+1);
    }

}
Console::~Console() {

}
void Console::run_menu() {
    int command;
    while(1){
        std::cout<<"1. Add \n";
        std::cout<<"2. List \n";
        std::cout<<"Enter a command: \n";
        std::cin>>command;
        if(command == 0)
            break;
        if(command == 1)
            this->add();
        if(command == 2)
            this->list();
        if(command == 3)
            this->pair();


    }
}