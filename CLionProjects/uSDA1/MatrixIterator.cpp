//
// Created by Ioana Jercan on 2019-03-26.
//
#include <exception>
#include "MatrixIterator.h"

MatrixIterator::MatrixIterator(const Matrix &m, int column): m(m) {
    this->line = 0;
    this->column = column;
}
void MatrixIterator::first() {
    this->line = 0;

}

TElem MatrixIterator::getCurrent() const {
    if (this->line >= m.nrLines())
        throw std::exception();
    return m.element(this->line, this->column);
}

void MatrixIterator::next() {
    if(this->line >= m.nrLines())
        throw std::exception();
    this->line++;
}

void MatrixIterator::previous() {
    if(this->line >= m.nrLines())
        throw std::exception();
    this->line--;

}

bool MatrixIterator::valid() const {
    return this->line >= m.nrLines();

}

