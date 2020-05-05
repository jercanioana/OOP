//
// Created by Ioana Jercan on 2019-05-14.
//

#ifndef DSALAB7_SORTEDBAGITERATOR_H
#define DSALAB7_SORTEDBAGITERATOR_H

#include "SortedBag.h"
#include <iostream>
#include <stack>


class SortedBag;
typedef int TComp;
class BSTNode;

class SortedBagIterator {

    friend class SortedBag;
    friend class BSTNode;
    private:

        //Constructor receives a reference of the container.

        //after creation the iterator will refer to the first element of the container, or it will be invalid if the container is empty

        SortedBagIterator(const SortedBag& sb);



        //contains a reference of the container it iterates over

        const SortedBag& sb;
        int currentNode;
        std::stack<int> stack;



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

        TComp getCurrent() const;



    };






#endif //DSALAB7_SORTEDBAGITERATOR_H
