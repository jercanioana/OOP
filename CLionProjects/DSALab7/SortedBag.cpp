//
// Created by Ioana Jercan on 2019-05-14.
//

#include "SortedBag.h"


SortedBag::SortedBag(Relation r) {//complexity theta(capacity)
    this->sizeOfBag = 0;
    this->firstEmpty = 1;
    this->capacity = 8;
    this->Nodes = new BSTNode[this->capacity];
    this->root = -1;
    this->next = new int[this->capacity];

    for(int i = 0; i < capacity; i++)
        this->next[i] = i+1;

    this->next[this->capacity] = -1;
    this->r = r;

}

SortedBagIterator SortedBag::iterator() const {//complexity theta(1)
    SortedBagIterator it = SortedBagIterator(*this);
    return it;
}

int SortedBag::size() const {//complexity theta(1)
    return this->sizeOfBag;
}

void SortedBag::add(TComp e) {//complexity O(n)
    int parent = -1; //the parent of the element
    if(this->firstEmpty >= this->capacity)
        this->resize();
    this->Nodes[this->firstEmpty].info = e;
    this->Nodes[this->firstEmpty].left = -1;
    this->Nodes[this->firstEmpty].right = -1;
    if(this->root == -1)//if the tree is empty
        this->root = this->firstEmpty;
    else {
        int currentNode = this->root;
        while (currentNode != -1) {
            parent = currentNode;
            if (this->r(e, this->Nodes[currentNode].info))
                currentNode = this->Nodes[currentNode].left;
            else
                currentNode = this->Nodes[currentNode].right;
        }
        if (this->r(e, this->Nodes[parent].info)) {
            this->Nodes[parent].left = this->firstEmpty;
            this->next[parent] = this->firstEmpty;
        } else {
            this->Nodes[parent].right = this->firstEmpty;
            this->next[parent] = this->firstEmpty;
        }
    }
    this->sizeOfBag++;
    this->firstEmpty = this->next[this->firstEmpty];

}

bool SortedBag::remove(TComp e) {
    bool is_removed = false;
    this->root = this->remove_rec(this->root, e, is_removed);
    if(is_removed){
        this->sizeOfBag--;
    }
    return is_removed;

}
int SortedBag::getMaximum(int node){// complexity O(n)
    int currentNode = node;
    int maximum = -1;
    if(currentNode == -1)
        return -1;
    else
        while(currentNode != -1){
            maximum = currentNode;
            currentNode = this->Nodes[currentNode].right;
        }
    return maximum;
}
int SortedBag::getMinimum(int start) { //complexity O(n)
    int currentNode = start;
    int minimum = -1;
    if(currentNode == -1)
        return -1;
    else
        while(this->Nodes[currentNode].left != -1){
            minimum = currentNode;
            currentNode = this->Nodes[currentNode].left;

        }
    return minimum;
}
int SortedBag::remove_rec(int node, TComp e, bool& is_removed) {//complexity O(n)
    int new_root;
    if(node == -1)
        return node;
    if(this->Nodes[node].info == e) {
        is_removed = true;
        if (this->Nodes[node].right == -1 and this->Nodes[node].left == -1) {//if there are no descendents
            this->Nodes[node].info = NULL;

        }
        if(this->Nodes[node].right == -1){//if there is no right descendant, we move the subtree determined by the left son over the one determined by the node
            new_root = this->Nodes[node].left;
            this->Nodes[node].left = -1;
            this->Nodes[node].right = -1;
            this->Nodes[node].info = NULL;
            return new_root;
        }
        else if(this->Nodes[node].left == -1){//if there is no left descendant
            new_root = this->Nodes[node].right;
            this->Nodes[node].left = -1;
            this->Nodes[node].right = -1;
            this->Nodes[node].info = NULL;
            return new_root;
        }
        else{//if we have 2 descendants, we replace the node to be deleted with the maximum and remove the maximum
            int maximum = this->getMaximum(this->Nodes[node].left);
            this->Nodes[node].info = this->Nodes[maximum].info;
            this->Nodes[node].left = this->remove_rec(this->Nodes[node].left, this->Nodes[maximum].info, is_removed);
        }

    }
    else{
        if(this->r(e, this->Nodes[node].info))
            //if the node is in the left subtree, we replace the root of the subtree determined by the initial left child with the left child
            this->Nodes[node].left = this->remove_rec(this->Nodes[node].left, e, is_removed);
        else
            //if the node is in the right subtree, we replace the root of the subtree determined by the initial right child with the right child
            this->Nodes[node].right = this->remove_rec(this->Nodes[node].right, e, is_removed);
    }
    return node;

}
bool SortedBag::isEmpty() const {// complexity theta(1)

    if(this->sizeOfBag == 0)
        return true;
    return false;
}

bool SortedBag::search(TComp e) const {// complexity O(n)
    int currentNode = this->root;
    bool found = false;
    while(currentNode != -1 and !found) {
        if (this->Nodes[currentNode].info == e)
            found = true;
        else if (this->r(e, this->Nodes[currentNode].info))
            currentNode = this->Nodes[currentNode].left;
        else
            currentNode = this->Nodes[currentNode].right;
    }
    return found;
}

int SortedBag::nrOccurrences(TComp e) const {// complexity O(n)
    int frequency = 0;
    int currentNode = this->root;
    while(currentNode != -1){
        if(this->Nodes[currentNode].info == e)
            frequency++;
        if(this->r(e, this->Nodes[currentNode].info))
            currentNode = this->Nodes[currentNode].left;
        else
            currentNode = this->Nodes[currentNode].right;
    }
    return frequency;
}


void SortedBag::resize() {//complexity theta(capacity)
    BSTNode* newNodes = new BSTNode[this->capacity*2];
    int* newNext = new int[this->capacity*2];
    for(int i = 0; i < this->capacity; i++) {
        newNodes[i] = this->Nodes[i];
        newNext[i] = this->next[i];
    }
    for (int i = capacity ; i < capacity*2; ++i)
        newNext[i] = i + 1;

    delete [] this->Nodes;
    this->Nodes = newNodes;
    delete [] this->next;
    this->next = newNext;

    this->firstEmpty = this->capacity+1;
    this->capacity *= 2;

}
void SortedBag::inorder_recursive(int node, int &counter) const {// complexity teta(n)
    int v[1001];
    if(node != -1) {
        inorder_recursive(this->Nodes[node].left, counter);
        for(int i = 0; i < this->sizeOfBag; i++)
        {
            v[this->Nodes[node].info] = 1;
        }
        inorder_recursive(this->Nodes[node].right, counter);
    }
    for(int i = 0; i < this->sizeOfBag; i++) {
        if(v[i] == 1) {
            counter++;
        }
    }

}
int SortedBag::uniqueCount() const {// complexity teta(1)

    int counter = 0;
    this->inorder_recursive(this->root, counter);
    return counter;
}

SortedBag::~SortedBag() {
    delete [] Nodes;
    delete [] next;
}
