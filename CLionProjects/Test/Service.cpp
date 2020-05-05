//
// Created by Ioana Jercan on 2019-04-10.
//

#include "Service.h"
void Service::add(const std::string &name, const std::string &runes) {
    ///this function receives as parameters the arguments for the item which will be added
    ///the function adds the new item to the list
    ///std::string : name -> the name of the powerWord
    ///std::string : runes -> the runes of the powerWord
    PowerWord powerWord {name, runes};
    this->repository.add(powerWord);
}

DynamicVector<PowerWord> Service::GetAll() {
    return this->repository.getAll();
}

Service::~Service() {

}
int Service::PowerWordAlreadyExists(const std::string& name) {
    DynamicVector<PowerWord> powerWords = this->GetAll();
    for(int index = 0; index<this->size(); index++) {
        if (powerWords[index].GetName() == name)
            return 1;
    }
    return 0;
}

int Service::size() {
    return this->repository.size();
}

int Service::OccurencesOfAGivenRune(const std::string& runes) {
    ///this function computes the number of occurences of a given rune type.
    /// It iterates trough the list of power words and when it finds an object which has that rune type, it increments the frequency.
    ///std::string runes : the type of runes
    ///returns the frequency

    DynamicVector<PowerWord> powerWords = this->GetAll();
    int numberOfRunes = this->size();
    int frequency = 0;
    for(int index = 0; index < numberOfRunes; index++) {
        if (powerWords[index].GetRunes() == runes)
            frequency++;
    }
    return frequency;
}