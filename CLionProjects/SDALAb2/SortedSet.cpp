//
// Created by Ioana Jercan on 2019-03-23.
//
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "SortedSet.h"
#include "Iterator.h"
#include <iostream>

//n - nr of nodes

SortedSet::SortedSet(Relation r) { // complexity Theta(1)
    this->head = NULL;
    this->relation = r;
    this->sizeOfSet = 0;
}
bool SortedSet::add(TComp e) { //complexity O(n)

    if (this->head == NULL) { // complexity Theta(1)
        SLLNode *newNode = new SLLNode;
        newNode->info.element = e;
        newNode->info.frequency++;
        newNode->next = this->head;
        this->head = newNode;
        this->sizeOfSet++;
        return true;
    }
    else if (this->relation(e, this->head->info.element) && e != this->head->info.element) { // complexity Theta(1)
        SLLNode *newNode = new SLLNode;
        newNode->info.element = e;
        newNode->next = this->head;
        newNode->info.frequency++;
        this->head = newNode;
        this->sizeOfSet++;
        return true;
    }
    else { // complexity O(n)
        SLLNode* currentNode = this->head;
        if (currentNode->info.element != e) {
            while (currentNode != NULL && currentNode->next != NULL && this->relation(currentNode->next->info.element, e)) {
                if(currentNode->info.element != e)
                    currentNode = currentNode->next;
                else
                    return false;
            }
            if(currentNode->info.element == e)
                return false;
            SLLNode *newNode = new SLLNode;
            newNode->info.element = e;
            newNode->next = currentNode->next;
            currentNode->next = newNode;
            newNode->info.frequency++;
            this->sizeOfSet++;
            return true;
        }
    }

    return false;

}
bool SortedSet::remove(TComp e) { // complexity O(n)
    SLLNode* currentNode = this->head;
    SLLNode* prevNode = NULL;
    while(currentNode != NULL && currentNode->info.element != e){
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode != NULL && prevNode == NULL) {
        this->head = this->head->next;
        this->sizeOfSet--;
        return true;
    }
    else if (currentNode != NULL) {
        prevNode->next = currentNode->next;
        currentNode->next = NULL;
        this->sizeOfSet--;
        return true;
    }
    return false;
}
bool SortedSet::search(TElem elem) const { // complexity O(n)
    SLLNode* current = this->head;
    while (current != NULL && current->info.element != elem){
        current = current->next;
    }
    if(current == NULL)
        return false;
    else
        return true;
}
int SortedSet::size() const { // complexity Theta(1)
    return this->sizeOfSet;
}
SortedSetIterator SortedSet::iterator() const { // complexity Theta(1)
    SortedSetIterator iteratorContainer(*this);
    return iteratorContainer;
}
bool SortedSet::isEmpty() const { // complexity Theta(1)
    if(this->size() == 0)
        return true;
    return false;
}

SortedSet::~SortedSet() {

}
