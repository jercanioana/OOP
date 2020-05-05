//
// Created by Ioana Jercan on 2019-04-10.
//

#ifndef TEST_REPOSITORY_H
#define TEST_REPOSITORY_H

#include "PowerWord.h"
#include "DynamicVector.h"

class Repository {
private:
    DynamicVector<PowerWord> powerWords;
public:
    Repository() {};
    void add(const PowerWord& powerWord);
    DynamicVector<PowerWord> getAll();
    int size();
    ~Repository();
};


#endif //TEST_REPOSITORY_H
