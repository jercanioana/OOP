//
// Created by Ioana Jercan on 2019-04-08.
//

#include "Repository.h"

void Repository::add(const Team &team) {
    teams.add(team);
}

int Repository::size() {
    return teams.getSize();
}

DynamicVector<Team> Repository::list() {
    return teams;
}

Team Repository::findByName(const std::string& name) {
    DynamicVector<Team> allTeams = this->list();
    for(int index = 0; index<this->size(); index++){
        if(strcmp(allTeams[index].getName().c_str(), name.c_str()) == 0)
            return allTeams[index];
    }
    return Team{"", "", 0};

}

void Repository::updateScore(const Team &team) {

}