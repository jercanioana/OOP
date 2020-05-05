//
// Created by Ioana Jercan on 2019-03-22.
//

#ifndef ASSIGNMENT5_DYNAMICVECTOR_H
#define ASSIGNMENT5_DYNAMICVECTOR_H


template <typename T>

class DynamicVector {
private:
    int size, capacity;
    T* Elements;
public:
    explicit DynamicVector(int capacity = 2);
    DynamicVector(const DynamicVector& vector);
    DynamicVector& operator=(const DynamicVector& vector);
    T& operator[](int position);
    void resize();
    void add(const T& element);
    void remove(int pos);
    void update(const T& element);
    T* GetAll();
    int getSize();
    ~DynamicVector();

};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity) {
    this->size = 0;
    this->capacity = capacity;
    this->Elements = new T[this->capacity];

}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector &vector) {
    this->size = vector.size;
    this->capacity = vector.capacity;
    this->Elements = new T[this->capacity];
    for (int index = 0; index < size; index++)
        this->Elements[index] = vector.Elements[index];
}
template <typename T>
T* DynamicVector<T>::GetAll() {
    return this->Elements;
}
template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector &vector) {
    if (this == &vector)
        return *this;
    this->capacity = vector.capacity;
    this->size = vector.size;

    delete[] this->Elements;
    this->Elements = new T[this->capacity];
    for (int index = 0; index < size; index++)
        this->Elements[index] = vector.Elements[index];
    return *this;

}
template <typename T>
void DynamicVector<T>::update(const T &element) {
    int index;
    for(index = 0; index < this->size; index++){
        if(strcmp(this->Elements[index].GetTitle().c_str(), element.GetTitle().c_str()) == 0)
            this->Elements[index] = element;
    }
}
template <typename T>
T& DynamicVector<T>::operator[](int position) {
    if ( position > this->size)
        return this->Elements[0];
    return this->Elements[position];

}
template <typename T>
DynamicVector<T>::~DynamicVector() {
    delete[] this->Elements;
}
template <typename T>
void DynamicVector<T>::add(const T& element) {
    if(this->size >= this->capacity)
        this->resize();
    this->Elements[this->size] = element;
    this->size++;
}

template <typename T>
int DynamicVector<T>::getSize() {
    return this->size;
}

template <typename T>
void DynamicVector<T>::remove(int positionForItem) {
    int index;
    int lengthOfList = this->size;
    for (index = positionForItem; index < lengthOfList - 1; index++) {
        this->Elements[index] = this->Elements[index + 1];
    }
    this->size--;
}

template <typename T>
void DynamicVector<T>::resize() {
    this->capacity *= 2;
    T *items = new T[this->capacity];
    for (int index = 0; index < this->size; index++)
        items[index] = this->Elements[index];

    this->Elements = items;
}

#endif //ASSIGNMENT5_DYNAMICVECTOR_H
