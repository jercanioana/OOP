//
// Created by Ioana Jercan on 2019-03-26.
//

#ifndef USDA1_MATRIXITERATOR_H
#define USDA1_MATRIXITERATOR_H



#include "Container.h"
class MatrixIterator {

private:
    int line, column;
    friend class Matrix;
    MatrixIterator(const Matrix &m, int column);
    const Matrix& m;

public:
    void first();
    void next();
    void previous();
    bool valid() const;
    TElem getCurrent() const;
};
#endif //USDA1_MATRIXITERATOR_H


