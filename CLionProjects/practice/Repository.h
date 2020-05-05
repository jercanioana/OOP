//
// Created by Ioana Jercan on 2019-04-08.
//

#ifndef PRACTICE_REPOSITORY_H
#define PRACTICE_REPOSITORY_H
#include "Team.h"
#include "DynamicVector.h"

class Repository {
private:
    DynamicVector<Team> teams;
public:
    Repository() {};
    void add(const Team& team);
    DynamicVector<Team> list();
    int size();
    Team findByName(const std::string& name);
    void updateScore(const Team& team);


};


#endif //PRACTICE_REPOSITORY_H
