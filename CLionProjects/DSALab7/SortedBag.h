//
// Created by Ioana Jercan on 2019-05-14.
//

#ifndef DSALAB7_SORTEDBAG_H
#define DSALAB7_SORTEDBAG_H


#pragma once

#include "SortedBagIterator.h"

typedef int TComp;

typedef TComp TElem;

typedef bool(*Relation)(TComp, TComp);
class SortedBagIterator;

class BSTNode{
    friend class SortedBagIterator;
    friend class SortedBag;
private:
    int right;
    int left;
    TComp info;

};
class SortedBag {

friend class SortedBagIterator;
friend class BSTNode;

private:

	/*representation of SortedBag*/
	int sizeOfBag;
	BSTNode* Nodes;
	int* next;
	int firstEmpty;
	int capacity;
	int root;
	Relation r;
	void resize();
	int remove_rec(int node, TComp e, bool& removed);
	int getMinimum(int start);
	int getMaximum(int start);
	void inorder_recursive(int node, int &counter) const;




public:

	//constructor

	SortedBag(Relation r);



	//adds an element to the sorted bag

	void add(TComp e);



	//removes one occurrence of an element from a sorted bag

	//returns true if an element was removed, false otherwise (if e was not part of the sorted bag)

	bool remove(TComp e);



	//checks if an element appearch is the sorted bag

	bool search(TComp e) const;



	//returns the number of occurrences for an element in the sorted bag

	int nrOccurrences(TComp e) const;



	//returns the number of elements from the sorted bag

	int size() const;



	//returns an iterator for this sorted bag

	SortedBagIterator iterator() const;



	//checks if the sorted bag is empty

	bool isEmpty() const;

	int uniqueCount() const;


	//destructor

	~SortedBag();

};


#endif //DSALAB7_SORTEDBAG_H
