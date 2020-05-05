//
// Created by Ioana Jercan on 2019-03-20.
//
#include <stdio.h>
#include <exception>
#include "MatrixIterator.h"


MatrixIterator Matrix::iterator(int column) const {
    if(column < 0)
        throw std::exception();
    MatrixIterator it(*this, column);
    return it;

}
Matrix::Matrix(int nrLines, int nrCols){
    this->number_lines = nrLines;
    this->number_columns = nrCols;


}

int Matrix::nrLines() const {
    return this->number_lines;
}

int Matrix::nrColumns() const {
    return this->number_columns;
}

TElem Matrix::element(int i, int j) const {
    int index;
    for(index = this->Lines[i]; index <= this->Lines[i+1]-1; index++){
        if(this->Columns[index] == j)
            return this->Values[index];
    }
    return 0;
}

TElem Matrix::modify(int i, int j, TElem e) {
    int index;
    TElem value;
    if( i<0 || j<0 || this->nrLines() < i || this->nrColumns() < j)
        throw std::exception();
    if( e != 0) {
        for (index = this->Lines[i]; index <= this->Lines[i + 1] - 1; index++) {
            if (this->Columns[index] == j) {
                value = this->Values[index];
                this->Values[index] = e;
                return value;
            }
        }
        if(this->size == this->capacity){
            this->capacity *= 2;
            TElem* v1 = new TElem[this->capacity];
            TElem* v2 = new TElem[this->capacity];
            for( int i1= 0; i1 <this->size; i1 ++)
            {
                v1[i] = this->Columns[i1];
                v2[i] = this->Values[i1];
            }
            this->Columns = v1;
            this->Values = v2;
        }
        int position = this->Lines[i];
        this->size++;
        while( j < this->Columns[position] && position < this->Lines[i]) position++;
        for( int i2 = size - 1; index < position; index++)
        {
            this->Lines[index] = this->Lines[index-1];
            this->Columns[index] = this->Columns[index-1];
        }
        this->Values[position] = e;
        this->Columns[position] = j;
        for (int i4 = i+1; i4 < this->nrLines(); i4++)
            this->Lines[i4]++;
        return e;

    }
        if(e == 0)
    {
        for (index = this->Lines[i]; index <= this->Lines[i + 1] - 1; index++) {
            if (this->Columns[index] == j) {
                value = this->Values[index];
                for(int index2 = index; index2 < size-1; index2++){
                    this->Columns[index2] = this->Columns[index2+1];
                    this->Values[index2] = this->Columns[index2+1];
                }
                this->size--;
                return value;

            }

            }


        }
        return 0;
}

Matrix::~Matrix() {
    delete[] this->Columns;
    delete[] this->Values;
}