//
// Created by Ioana Jercan on 2019-05-07.
//

#ifndef PRACTICE3_UI_H
#define PRACTICE3_UI_H

#include "Controller.h"
#include "Surgery.h"
#include "NeonatalUnit.h"

class UI {
private:
    Controller controller;
public:
    UI(Controller& controller1): controller{controller1} {}
    void Add();
    void RunMenu();
    void List();
    void ListEff();
    ~UI();

};


#endif //PRACTICE3_UI_H
