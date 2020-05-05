//
// Created by Ioana Jercan on 2019-04-08.
//

#ifndef PRACTICE_SERVICE_H
#define PRACTICE_SERVICE_H

#include "Repository.h"

class Service {
private:
    Repository repository;
public:
    Service(Repository& repository1): repository(repository1) {};
    void add(const std::string& name, const std::string& country, const int score);
    DynamicVector<Team> list();
    int size();
    Team findByName(const std::string& name);
    ~Service();
};


#endif //PRACTICE_SERVICE_H
