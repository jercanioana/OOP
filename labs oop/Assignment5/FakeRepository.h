//
// Created by Ioana Jercan on 2019-05-18.
//
#include "FileManager.h"

#ifndef ASSIGNMENT5_FAKEREPOSITORY_H
#define ASSIGNMENT5_FAKEREPOSITORY_H


class FakeRepository: public FileManager {
public:
    FakeRepository(std::vector<Chore> chores, std::vector<Chore> myList);
    std::vector<Chore> GetElements() override;
    ~FakeRepository();

};

class FakeCSVRepository: public CSVFileManager{
public:
    FakeCSVRepository(std::vector<Chore> chores, std::vector<Chore> myList);
    std::vector<Chore> GetElements() override;
    ~FakeCSVRepository();
};

class FakeHTMLRepository: public HTMLFileManager{
public:
    FakeHTMLRepository(std::vector<Chore> chores, std::vector<Chore> myList);
    std::vector<Chore> GetElements() override;
    ~FakeHTMLRepository();
};


#endif //ASSIGNMENT5_FAKEREPOSITORY_H
