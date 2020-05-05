//
// Created by Ioana Jercan on 2019-04-06.
//

#ifndef SDALAB4_SMMITERATOR_H
#define SDALAB4_SMMITERATOR_H

#include "SortedMultiMap.h"

class SMMIterator {
    friend class SortedMultiMap;
private:
    Node* currentK;
    TElem currentV;

    //Constructor receives a reference of the container.

    //after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty

    SMMIterator(const SortedMultiMap& smm);

    //contains a reference of the container it iterates over

    const SortedMultiMap& smm;

    /* representation specific for the iterator*/



public:



    //sets the iterator to the first element of the container

    void first();



    //moves the iterator to the next element

    //throws exception if the iterator is not valid

    void next();



    //checks if the iterator is valid

    bool valid() const;



    //returns the value of the current element from the iterator

    // throws exception if the iterator is not valid

    TElem getCurrent() const;

};


#endif //SDALAB4_SMMITERATOR_H
