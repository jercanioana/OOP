//
// Created by Ioana Jercan on 2019-04-17.
//
#include "P2.h"
#include <iostream>
#include "Heap.h"
vector<TElem> mergeVectors(vector<vector<TElem>> inputVectors, Relation rel)
{
    Heap heap(rel);
    vector<TElem> result;
    for (int i = 0; i < inputVectors.size(); i++)
    {
        if (inputVectors[i].size() >= 1)
        {

            Triple elem{ inputVectors[i][0], i, 0 };
            heap.add(elem);
        }
    }
    //Complexity : O(N * log2 k) N-total nr of elements
    while (heap.getsize() > 0)
    {
        Triple elem = heap.remove();
        result.push_back(elem.elem);
        if (elem.position + 1 < inputVectors[elem.vector].size())
        {
            Triple new_elem{ inputVectors[elem.vector][elem.position + 1], elem.vector, elem.position + 1 };
            heap.add(new_elem);
        }
    }
    return result;


}


