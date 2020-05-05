//
// Created by Ioana Jercan on 2019-04-08.
//

#ifndef PRACTICE_CONSOLE_H
#define PRACTICE_CONSOLE_H
#include "Service.h"

class Console {
private:
    Service service;
public:
    Console(Service& service1) : service(service1) {};
    void add();
    void run_menu();
    void list();
    void pair();
    ~Console();
};


#endif //PRACTICE_CONSOLE_H
