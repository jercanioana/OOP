//
// Created by Ioana Jercan on 2019-04-06.
//
#include "vector"
#include "SortedMultiMap.h"

SortedMultiMap::SortedMultiMap(Relation r) { // Complexity O(n)
    this->capacity = 1;
    this->relation = r;
    this->sizeOfMap = 0;
    this->elems = new TElem[this->capacity];
    this->next = new int[this->capacity];
    this->head = -1;
    for(int i=1; i<=this->capacity; i++){
        this->next[i] = i+1;
    }
    this->next[this->capacity] = -1;
    this->firstEmpty = 1;


}

vector<TValue> SortedMultiMap::search(TKey c) const {
   int current = this->head;
    while(current != -1 && this->elems[current] != c){
        current = this->next[current];
    }
    if(current != -1)
        return current;
    else
        return false;


}

int SortedMultiMap::size() const {
    return this->sizeOfMap;
}

bool SortedMultiMap::remove(TKey c, TValue v) {
    int nodeC = this->head;
    int prevNode = -1;
    while (nodeC!= -1 && this->elems[nodeC] != )
}

SMMIterator SortedMultiMap::iterator() const {

}

void SortedMultiMap::add(TKey c, TValue v) {

}

bool SortedMultiMap::isEmpty() const {
    if(this->sizeOfMap == 0)
        return true;
    else
        return false;
}

SortedMultiMap::~SortedMultiMap() {
    int auxNode;
    while(this->head != NULL){

        auxNode = this->head;
        this->head = this->head->next;
        free(auxNode->info.vl);
        free(auxNode);

    }
}