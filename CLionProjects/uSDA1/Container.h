//
// Created by Ioana Jercan on 2019-03-20.
//

#ifndef USDA1_CONTAINER_H
#define USDA1_CONTAINER_H




class MatrixIterator;

typedef int TElem;

class Matrix{
private:
    int Lines[20];
    int* Columns;
    int* Values;
    int number_lines, number_columns;
    int size, capacity;


public:
    Matrix(int nrLines, int nrCols);
    int nrLines() const;
    int nrColumns() const;
    TElem element(int i, int j) const;
    TElem modify(int i, int j, TElem e);
    MatrixIterator iterator(int column) const;
    ~Matrix();


};
#endif //USDA1_CONTAINER_H