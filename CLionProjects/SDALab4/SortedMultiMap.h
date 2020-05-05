//
// Created by Ioana Jercan on 2019-04-06.
//

#ifndef SDALAB4_SORTEDMULTIMAP_H
#define SDALAB4_SORTEDMULTIMAP_H

#include "SMMIterator.h"
#include <utility>

typedef std::pair<TKey, TValue> TElem;


using namespace std;



typedef bool(*Relation)(TKey, TKey);
typedef struct Node{
    TElem info;
    Node* next;

};


class SortedMultiMap {

friend class SMMIterator;

private:


    /* representation of the SortedMultiMap */
    int head;
    int next[];
    Relation relation;
    int capacity;
    int firstEmpty;
    TElem* elems;
    int sizeOfMap;


public:



    // constructor

    SortedMultiMap(Relation r);



    //adds a new key value pair to the sorted multi map

    void add(TKey c, TValue v);



    //returns the values belonging to a given key

    vector<TValue> search(TKey c) const;



    //removes a key value pair from the sorted multimap

    //returns true if the pair was removed (it was part of the multimap), false if nothing is removed

    bool remove(TKey c, TValue v);



    //returns the number of key-value pairs from the sorted multimap

    int size() const;



    //verifies if the sorted multi map is empty

    bool isEmpty() const;



    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)

    SMMIterator iterator() const;



    // destructor

    ~SortedMultiMap();

};



#endif //SDALAB4_SORTEDMULTIMAP_H
