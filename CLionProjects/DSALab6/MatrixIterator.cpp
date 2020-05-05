//
// Created by Ioana Jercan on 2019-05-14.
//
#include <iostream>
#include "MatrixIterator.h"

MatrixIterator::MatrixIterator(const Matrix& m, int line): m(m), line(line)  { //complexity teta(1)
    this->column = 0;
}

void MatrixIterator::first() { // complexity teta(1)
    this->column = 0;
}

void MatrixIterator::next() { //complexity teta(1)
    if(this->valid())
        this->column++;

}

bool MatrixIterator::valid() const { //complexity teta(1)
    if(this->column >= m.nrColumns())
        return 0;
    return 1;
}

TElem MatrixIterator::getCurrent() const { //complexity teta(1)
    if(this->valid()) {
        return m.element(this->line, this->column);
    }
    return 0;
}