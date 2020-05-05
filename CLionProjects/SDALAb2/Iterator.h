//
// Created by Ioana Jercan on 2019-03-30.
//

#ifndef SDALAB2_ITERATOR_H
#define SDALAB2_ITERATOR_H
#include "SortedSet.h"
class SortedSet;

class SortedSetIterator
{
    friend class SortedSet;

private:
    //the iterator stores a reference to the container
    const SortedSet& set;
    //other specific attributes: current, etc
    SLLNode* current;

    SortedSetIterator(const SortedSet& s);

public:
    TElem getCurrent();
    bool valid();
    void next();
    void first();
    void jumpForward(int k);
};




#endif //SDALAB2_ITERATOR_H
