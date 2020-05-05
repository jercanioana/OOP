//
// Created by Ioana Jercan on 2019-03-23.
//

#include "Repository.h"
#include "FileManager.h"
#include <string>

void Repository::AddElement(const Chore &chore) {
    this->chores.push_back(chore);

}
int Repository::Size()
{
    return this->chores.size();
}
int Repository::SizeOfMyList() {
    return this->myList.size();
}
std::vector<Chore> Repository::GetElements() {
    return this->chores;
}
Chore Repository::operator[](int position) {
    if ( position < this->chores.size())
        return this->chores[0];
    return this->chores[position];
}
void Repository::RemoveElement(const std::string &title) {
    int position = this->FindPosition(title);
    this->chores.erase(this->chores.begin()+position);

}
Chore Repository::FindByTitle(const std::string &title) {
    for(auto & chore : chores) {
        if (chore.GetTitle() == title)
            return chore;
    }
    return Chore{"", "", "", 0, ""};
}

void Repository::UpdateElement(const Chore &chore) {
    for(auto & iterator : chores) {
        if (iterator.GetTitle() == chore.GetTitle())
            iterator = chore;
    }
}

void Repository::SaveElement(const std::string &title) {
    Chore chore = this->FindByTitle(title);
    myList.push_back(chore);

}

std::vector<Chore> Repository::GetMyList() {
    return this->myList;
}

int Repository::FindPosition(const std::string &title) {

    int position = 0;
    for(auto & iterator : chores) {
        if (iterator.GetTitle() == title)
            return position;
        position++;
    }
    return -1;

}