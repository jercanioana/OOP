//
// Created by Ioana Jercan on 2019-05-04.
//

#ifndef PRACTICE2_PERSON_H
#define PRACTICE2_PERSON_H

#include "Analysis.h"
#include <vector>

class Person {
private:
    std::string name;
    std::vector<Analysis> analyses;
public:
    Person() = default;
    void addAnalysis(Analysis analysis);
    std::vector<Analysis> GetAllAnalyses() {return analyses;}
    ~Person() { };



};


#endif //PRACTICE2_PERSON_H
