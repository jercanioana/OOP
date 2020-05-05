//
// Created by Ioana Jercan on 2019-05-04.
//

#ifndef PRACTICE2_CONSOLE_H
#define PRACTICE2_CONSOLE_H

#include "Service.h"

class Console {
private:
    Service service;
public:
    Console(Service service): service{service} {}
    void Add();
    void RunMenu();
    ~Console();
};


#endif //PRACTICE2_CONSOLE_H
