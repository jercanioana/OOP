//
// Created by Ioana Jercan on 2019-04-25.
//

#include "Matrix.h"
#include "MatrixIterator.h"
#include <iostream>
#include <exception>

Matrix::Matrix(int nrLines, int nrCols) { // complexity O(m)
    if(nrLines <= 0 or nrCols <= 0)
        throw std::exception();
    this->lines = nrLines;
    this->columns = nrCols;
    this->m = 19;
    this->FirstFree = 0;
    this->FirstElement = -1;
    this->T = new TKey[this->m];
    for(int i=0; i<m; ++i){
        this->T[i].value = -1;
    }
    this->next = new int[this->m];
    for(int i=0; i<m; ++i){
        this->next[i] = -1;
    }
}


int Matrix::nrColumns() const { // complexity theta(1)
    return this->columns;
}

int Matrix::nrLines() const { // complexity theta(1)
    return this->lines;
}

TElem Matrix::element(int i, int j) const { // complexity O(m)

    if( i<0 || j<0 || this->nrLines() < i || this->nrColumns() < j)
        throw std::exception();
    int index = 0;
    while(index < this->m) {
        int pos = h(this->T[index].value);
        while (pos != -1 and (this->T[pos].line != i or this->T[pos].column != j)) {
            pos = this->next[pos];
        }
        if (pos != -1 and T[pos].line == i and T[pos].column == j)
            return this->T[pos].value;
        else
            index++;
    }
    return 0;
}


void Matrix::changeFirstFree() { // complexity O(m)
    this->FirstFree += 1;
    while (this->FirstFree < this->m and T[this->FirstFree].value != -1){
        this->FirstFree += 1;
    }
}

void Matrix::changeFirstFreeRehash(TKey* newT) { // complexity O(m)
    this->FirstFree += 1;
    while (this->FirstFree < this->m and newT[this->FirstFree].value != -1){
        this->FirstFree += 1;
    }
}


void Matrix::rehash() { // complexity O(m)

    int oldM;
    oldM = m;
    m *= 2;
    int current = 0;
    TKey* newT = new TKey[this->m];
    int* newNext = new int[this->m];
    int pos;
    for(int i = 0; i < m; i++){
        newT[i].value = -1;
    }
    for(int i = 0; i< oldM; ++i)
        newNext[i] = this->next[i];
    for(int i = oldM; i < this->m; ++i)
        newNext[i] = -1;
    delete[] this->next;
    this->next = newNext;
    this->FirstFree = 0;

    for(int i = 0; i < oldM; i++){
        pos = h(this->T[i].value);

        if(newT[pos].value == -1) {
            newT[pos] = this->T[i];
            newNext[pos] = -1;
            if(pos == this->FirstFree)
                changeFirstFreeRehash(newT);

        }

        else{
            current = pos;
            newT[this->FirstFree] = this->T[i];
            newNext[this->FirstFree] = -1;
            while (newNext[current] != -1) {
                current = newNext[current];
            }
            newNext[current] = this->FirstFree;
            changeFirstFreeRehash(newT);

        }
    }
    delete[] this->T;
    this->T = newT;



}


TElem Matrix::modify(int i, int j, TElem e) { // complexity O(m)
    if (i < 0 || j < 0 || this->nrLines() < i || this->nrColumns() < j)
        throw std::exception();
    int pos;
    pos = h(e);
    TKey new_element;
    new_element.column = j;
    new_element.line = i;
    new_element.value = e;
    int current;
    int index = 0;
    if(this->FirstFree == this->m){
        rehash();
    }
    while(index < this->m) {
        if(this->T[index].line == i and this->T[index].column == j) {
            if (e != 0) {
                int old_element = this->T[index].value;
                this->T[index].value = e;
                return old_element;
            } else {
                int current_pos = pos;
                int prev = -1;
                int index = 0;
                while(index < this->m and prev == -1){
                    if(this->next[index] == i)
                        prev = index;
                    else
                        index++;
                }
                while(pos != -1 and this->T[pos].value != e){
                    prev = pos;
                    pos = this->next[pos];
                }
                if(pos == -1){
                    return 0;

                }
                else {
                    bool over = false;
                    do {
                        int p = this->next[pos];
                        int pp = pos;
                        while (p != -1 and this->h(this->T[p].value) != pos) {
                            pp = p;
                            p = this->next[p];
                        }
                        if (p == -1) {
                            over = true;

                        } else {
                            this->T[i] = this->T[p];
                            prev = pp;
                            pos = p;
                        }
                    }while(over);
                    if(prev != -1){
                        this->next[prev] = this->next[pos];

                    }
                    this->T[pos].value = -1;
                    this->next[pos] = -1;
                    if(this->FirstFree > pos)
                        this->FirstFree = pos;


                }

                return current_pos;

            }
        }
        else{
            if(this->T[pos].value == -1){
                this->T[pos].value = e;
                this->T[pos].line = i;
                this->T[pos].column = j;
                this->next[pos] = -1;
                size++;
                if(pos == this->FirstFree)
                    changeFirstFree();
                return 0;

            }
            else{
                current = pos;
                this->T[this->FirstFree] = new_element;
                this->next[this->FirstFree] = -1;

                while(this->next[current] != -1){
                    current = this->next[current];
                }
                this->next[current] = this->FirstFree;
                changeFirstFree();
                size++;
                return 0;

            }


        }

    }

    return 0;
}

MatrixIterator Matrix::iterator(int line) const { // complexity teta(1)
    if( line > this->nrLines() || line < 0){
        throw std::exception();
    }
    MatrixIterator iterator(*this, line);
    return iterator;
}

