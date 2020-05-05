//
// Created by Ioana Jercan on 2019-03-23.
//

#ifndef ASSIGNMENT5_UI_H
#define ASSIGNMENT5_UI_H

#include "Service.h"

class UI {
private:
    Service& service;
public:
    void List();
    explicit UI(Service& service);
    void Remove(const std::string &command);
    void Update(const std::string &command);
    void Add(const std::string &command);
    void Filter(const std::string &command);
    void Next(int counter);
    void Save(const std::string &command);
    void MyList();
    void RunMenu();
    void FileLocation(const std::string& command);
    void MyListFileLocation(const std::string& command);
    ~UI();

};


#endif //ASSIGNMENT5_UI_H
