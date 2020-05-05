//
// Created by Ioana Jercan on 2019-04-06.
//
#include "exception"
#include "SMMIterator.h"
 SMMIterator::SMMIterator(const SortedMultiMap &smm): smm(smm){ // Complexity Theta(1)
    this->currentK = smm.head;
    if(smm.head != NULL)
        SMMIterator(smm.head->info, this->currentV)

}

void SMMIterator::first() {
    this->currentK = smm.head;


}

void SMMIterator::next() {
    if(this->valid()){

        if(valid(this->))
    }

}

bool SMMIterator::valid() const {
    if(this->currentK == NULL)
        return false;
    else
        return true;

}
TElem SMMIterator::getCurrent() const {

}