//
// Created by Ioana Jercan on 2019-05-14.
//

#ifndef DSALAB6_MATRIXITERATOR_H
#define DSALAB6_MATRIXITERATOR_H

#include "Matrix.h"

class Matrix;

class MatrixIterator {
    friend class Matrix;

private:

    MatrixIterator(const Matrix& m, int line);
    const Matrix& m;
    int column;
    int line;
    TElem current;

public:

    void first();
    TElem getCurrent() const;
    void next();
    bool valid() const;

};


#endif //DSALAB6_MATRIXITERATOR_H
