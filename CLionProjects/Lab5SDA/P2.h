//
// Created by Ioana Jercan on 2019-04-17.
//

#ifndef LAB5SDA_P2_H
#define LAB5SDA_P2_H
#include <vector>
#include "DynamicArray.h"
using namespace std;

typedef int TElem;
typedef bool(*Relation) (TElem e1, TElem e2);
typedef struct {
    TElem elem;
    int vector;
    int position;
}Triple;


//merges k sorted vectors into one single vector.
//the input vectors are sorted considering the relation and the results should be sorted in the same way.
vector<TElem> mergeVectors(vector<vector<TElem>> inputVectors, Relation rel);
#endif //LAB5SDA_P2_H
