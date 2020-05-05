//
// Created by Ioana Jercan on 2019-04-10.
//

#include "Console.h"
void Console::add() {
    std::string name;
    std::string runes;
    std::cout<<"Enter a name: ";
    std::cin.get();
    std::getline(std::cin, name);
    std::cout<<"Enter runes: ";
    std::getline(std::cin, runes);
    if(this->service.PowerWordAlreadyExists(name)  == 0) {
        this->service.add(name, runes);
        std::cout << "Power word added. \n";
    }
    else
        std::cout<< "Power word already exists. \n";

}

void Console::list() {
    DynamicVector<PowerWord> powerWords = this->service.GetAll();
    int numberOfRunes = this->service.size();
    for(int index = 0; index < numberOfRunes; index++){
        if(strcmp(powerWords[index].GetName().c_str(), powerWords[index+1].GetName().c_str()) == -1){
            PowerWord auxilaryPowerWord = powerWords[index];
            powerWords[index] = powerWords[index+1];
            powerWords[index+1] = auxilaryPowerWord;
        }

    }
    for(int index = 0; index < numberOfRunes; index++) {
        std::cout << powerWords[index].GetName() << " " << powerWords[index].GetRunes() << "\n";
    }
}
void Console::MostUsedRune() {
    DynamicVector<PowerWord> powerWords = this->service.GetAll();
    PowerWord maximumPowerWord;
    int numberOfRunes = this->service.size();
    int maxOccurences = 0;
    for(int index=0; index< numberOfRunes; index++){
        if(this->service.OccurencesOfAGivenRune(powerWords[index].GetRunes()) > maxOccurences)
        {
            maxOccurences = this->service.OccurencesOfAGivenRune(powerWords[index].GetRunes());
            maximumPowerWord = powerWords[index];
        }
    }
    std::cout<<maximumPowerWord.GetRunes()<<'\n';



}
void Console::run_menu() {
    int command;
    while(1){
        std::cout<<"Enter a command: ";
        std::cin>>command;
        if(command == 0)
            break;
        if(command == 1)
            this->add();
        if(command == 2)
            this->list();
        if(command == 3)
            this->MostUsedRune();
    }
}

Console::~Console() {

}