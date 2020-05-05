//
// Created by Ioana Jercan on 2019-03-23.
//

#ifndef ASSIGNMENT5_REPOSITORY_H
#define ASSIGNMENT5_REPOSITORY_H
#include "Chore.h"
#include "DynamicVector.h"
#include "vector"
class Repository {
protected:
    std::vector<Chore> chores;
    std::vector<Chore> myList;

public:
    Repository() = default;
    virtual void AddElement(const Chore& chore);
    virtual void RemoveElement(const std::string& title);
    virtual void UpdateElement(const Chore& chore);
    int Size();
    int SizeOfMyList();
    virtual void SaveElement(const std::string& title);
    virtual Chore FindByTitle(const std::string& title);
    Chore operator[](int i);
    virtual std::vector<Chore> GetElements();
    std::vector<Chore> GetMyList();
    int FindPosition(const std::string& title);


};


#endif //ASSIGNMENT5_REPOSITORY_H
