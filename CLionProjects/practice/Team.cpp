//
// Created by Ioana Jercan on 2019-04-08.
//

#include "Team.h"

Team::Team() : name {""}, country{""}, score{} {

}
Team::Team(const std::string& newName, const std::string& newCountry, const int newScore) :
    name{newName}, country{newCountry}, score{newScore}
{
}

Team::~Team() {

}