//
// Created by Ioana Jercan on 2019-04-18.
//
#include "Heap.h"
Heap::Heap(Relation r)
//Teta(1)
{
    this->lenght = 0;
    this->capacity = 5;
    this->rel = r;
    this->elems = new Triple[5];
}



void Heap::add(Triple e)
//Complexity : O(log2 N) N - number of elements in heap
{
    if (this->lenght == this->capacity)
        this->resize();
    this->elems[this->lenght] = e;
    this->lenght++;
    this->bubble_up(this->lenght - 1);
}

Triple Heap::remove()
//Complexity : O(log2 N) N - number of elements in heap
{
    if (this->lenght != 0)
    {
        Triple deletedElem = this->elems[0];
        this->elems[0] = this->elems[this->lenght - 1];
        this->lenght--;
        this->bubble_down(0);
        return deletedElem;
    }
}

void Heap::resize()
//Complexity Teta(N) N - number of elements in heap
{
    this->capacity *= 2;
    Triple* newlist = new Triple[this->capacity];
    for (int index = 0; index < this->lenght; index++)
        newlist[index] = this->elems[index];
    this->elems = newlist;
}

int Heap::getsize()
//Teta(1)
{
    return this->lenght;
}

void Heap::bubble_up(int p)
//Complexity : O(log2 N) N - number of elements in heap
{
    int poz = p;
    Triple elem = this->elems[p];
    int parent = (p-1) / 2;
    while (poz > 0 && this->rel(elem.elem, this->elems[parent].elem) == 1)
    {
        this->elems[poz] = this->elems[parent];
        poz = parent;
        parent = (poz-1) / 2;
    }
    this->elems[poz] = elem;
}

void Heap::bubble_down(int p)
//Complexity : O(log2 N) N - number of elements in heap
{
    int poz = p;
    Triple elem = this->elems[p];
    while (poz < this->lenght - 1)
    {
        int maxchild = -1;
        if (poz * 2 + 1 < this->lenght)
            maxchild = poz * 2 + 1;
        if (poz * 2 + 2 < this->lenght&&this->rel(this->elems[2 * poz + 2].elem, this->elems[2 * poz + 1].elem) == 1)
            maxchild = poz * 2 + 2;
        if (maxchild != -1 && this->rel(this->elems[maxchild].elem, elem.elem))
        {
            Triple tmp = this->elems[poz];
            this->elems[poz] = this->elems[maxchild];
            this->elems[maxchild] = tmp;
            poz = maxchild;
        }
        else
        {
            poz = this->lenght;
        }
    }
}

Heap::~Heap()
{
}
