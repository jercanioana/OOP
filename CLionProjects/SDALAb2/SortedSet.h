//
// Created by Ioana Jercan on 2019-03-23.
//

#ifndef SDALAB2_SORTEDSET_H
#define SDALAB2_SORTEDSET_H


typedef int TElem;

typedef TElem TComp;

class SortedSetIterator;

typedef bool(*Relation)(TComp, TComp);

typedef struct{
    TComp element;
    int frequency;

}pair;
struct SLLNode{
    pair info;
    SLLNode* next;
};

class SortedSet {
    friend class SortedSetIterator;
private:
    Relation relation;
    SLLNode* head;
    int sizeOfSet;

public:


    //constructor

    SortedSet(Relation r);



    //adds an element to the sorted set

    //if the element was added, the operation returns true, otherwise (if the element was already in the set)

    //it returns false

    bool add(TComp e);





    //removes an element from the sorted set

    //if the element was removed, it returns true, otherwise false

    bool remove(TComp e);



    //checks if an element is in the sorted set

    bool search(TElem elem) const;





    //returns the number of elements from the sorted set

    int size() const;



    //checks if the sorted set is empty

    bool isEmpty() const;



    //returns an iterator for the sorted set

    SortedSetIterator iterator() const;



    // destructor

    ~SortedSet();


};



#endif //SDALAB2_SORTEDSET_H
