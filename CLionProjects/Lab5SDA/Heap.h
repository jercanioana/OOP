//
// Created by Ioana Jercan on 2019-04-18.
//

#ifndef LAB5SDA_HEAP_H
#define LAB5SDA_HEAP_H


#include "P2.h"
class Heap
{
private:
    int capacity;
    int lenght;
    Relation rel;
    Triple* elems;
public:
    Heap(Relation r);
    void add(Triple e);
    Triple remove();
    void resize();
    int getsize();
    void bubble_up(int p);
    void bubble_down(int p);
    ~Heap();
};




#endif //LAB5SDA_HEAP_H
