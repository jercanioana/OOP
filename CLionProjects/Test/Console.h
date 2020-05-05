//
// Created by Ioana Jercan on 2019-04-10.
//

#ifndef TEST_CONSOLE_H
#define TEST_CONSOLE_H

#include "Service.h"

class Console {
private:
    Service service;
public:
    Console(Service& service1) : service(service1) {};
    void add();
    void list();
    ~Console();
    void run_menu();
    void MostUsedRune();
};


#endif //TEST_CONSOLE_H
