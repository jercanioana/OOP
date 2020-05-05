//
// Created by Ioana Jercan on 2019-03-30.
//
#include "exception"
#include "Iterator.h"
#include "SortedSet.h"
SortedSetIterator::SortedSetIterator(const SortedSet& s): set(s) { // complexity Theta(1)
    //initialize current and other specific attributes
    this->current = set.head;
}

TElem SortedSetIterator::getCurrent() { // complexity Theta(1)
    if(this->current == NULL){
        throw std::exception();
    }
    TElem e = this->current->info.element;
    return e;
}

bool SortedSetIterator::valid() { // complexity Theta(1)
    if(this->current == NULL)
        return false;
    else
        return true;
}

void SortedSetIterator::next() { // complexity Theta(1)
    if(this->current == NULL){
        throw std::exception();
    }
    this->current = this->current->next;
}

void SortedSetIterator::first() { // complexity Theta(1)
    this->current = set.head;
}

void SortedSetIterator::jumpForward(int k) { // complexity Theta(k)
    if(k <= 0)
        throw std::exception();
    else if(k > this->set.size()){
        this->current == NULL;
        throw std::exception();
    }

    else {
        while (k != 0) {
            if (this->valid()) {
                this->next();
                k--;
            }
        }
    }
}

