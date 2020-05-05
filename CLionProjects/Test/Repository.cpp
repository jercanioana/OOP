//
// Created by Ioana Jercan on 2019-04-10.
//

#include "Repository.h"
void Repository::add(const PowerWord &powerWord) {
    /// This function adds a new powerWord to the list of powerWords
    ///powerWords: the item which needs to be added.
    powerWords.add(powerWord);
}

DynamicVector<PowerWord> Repository::getAll() {
    return powerWords;
}

Repository::~Repository() {

}
//PowerWord Repository::findByName(const std::string &name) {
//    DynamicVector<PowerWord> powerWords = this->getAll();
//    for(int index = 0; index<this->size(); index++) {
//        if (powerWords[index].GetName() == name)
//            return powerWords[index];
//        else
//            return PowerWord{" ", " "};
//    }
//}

int Repository::size() {
    return powerWords.getSize();
}