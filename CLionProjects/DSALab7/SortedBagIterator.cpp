//
// Created by Ioana Jercan on 2019-05-14.
//

#include "SortedBagIterator.h"
#include <exception>

SortedBagIterator::SortedBagIterator(const SortedBag &sb): sb(sb) {//complexity theta(1)
    this->first();
}

TComp SortedBagIterator::getCurrent() const {// complexity theta(1)
    if(!valid()){
        throw std::exception();
    }
    return sb.Nodes[this->currentNode].info;
}

void SortedBagIterator::next() {// complexity O(n)
    if(!valid()){
        throw std::exception();
    }

    int node = this->stack.top();
    stack.pop();
    if(sb.Nodes[node].right != -1){
        node = sb.Nodes[node].right;
        while(node != -1) {
            this->stack.push(node);
            node = sb.Nodes[node].left;
        }
    }
    if (!this->stack.empty()){
        this->currentNode = this->stack.top();
    }
    else
        this->currentNode = -1;

}

bool SortedBagIterator::valid() const {// complexity theta(1)
    if(this->currentNode != -1)
        return true;
    return false;
}

void SortedBagIterator::first() {// complexity O(n)
    this->currentNode = sb.root;
    while(this->currentNode != -1){
        this->stack.push(this->currentNode);
        this->currentNode = sb.Nodes[this->currentNode].left;

    }
    if (!this->stack.empty()){
        this->currentNode = this->stack.top();
    }
    else
        this->currentNode = -1;
}