//
// Created by Ioana Jercan on 2019-04-10.
//

#ifndef TEST_SERVICE_H
#define TEST_SERVICE_H

#include "Repository.h"

class Service {
private:
    Repository repository;
public:
    Service(Repository& repository1) : repository(repository1) {};
    void add(const std::string& name, const std::string& runes);
    DynamicVector<PowerWord> GetAll();
    int size();
    int PowerWordAlreadyExists(const std::string& name);
    int OccurencesOfAGivenRune(const std::string& runes);
    ~Service();
};


#endif //TEST_SERVICE_H
