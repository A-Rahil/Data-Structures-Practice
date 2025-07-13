#include <iostream>
#include <cassert>
#include "ArrayLists.h"
//The methods of the class
template <class elemType>
void ArrayBList<elemType>::remove(const elemType &item) {
    int loc;
    if (length == 0)
        std::cerr << "Cannot delete from an empty list" << std::endl;
    else {
        loc = SequentialSearch(item);
        if (loc != -1)
            removeAtIndex(loc);
        else 
            std::cout << "The item doesn't exist in the list" << std::endl;
    }
}
template <class elemType>
void ArrayBList<elemType>::insert(const elemType &item) {
    int location;
    if (isEmpty())
        list[length++] = item;
    else if (isFull())
        std::cerr << "Cannot insert to a full list" << std::endl;
    else {
        location = SequentialSearch(item);
        if (location == -1) 
            list[length++] = item;
        else
            std::cerr << "The item already exists in the list" << std::endl;
    }
}
template <class elemType>
int ArrayBList<elemType>::SequentialSearch(const elemType &searchItem) const{
    for (int i = 0; i < length; i++) {
        if(isItemAtIndexEqual(i, searchItem))
            return i;
    }
    return -1;
}
template <class elemType>
ArrayBList<elemType>& ArrayBList<elemType>::operator=(const ArrayBList<elemType> &RHS) {
    if (this != RHS) {
        length = RHS.length;
        maxSize = RHS.maxSize;
        list = new elemType[maxSize];
        assert(list != NULL);
        for (int i = 0; i < RHS.length; i++)
            list[i] = RHS.list[i];
    }
    return *this;
}
template <class elemType>
ArrayBList<elemType>::ArrayBList(const ArrayBList<elemType> &other) {
    length = other.length;
    maxSize = other.maxSize;
    delete [] list;
    list = new elemType[maxSize];
    assert(list != NULL);
    for (int i = 0; i < other.length; i++)
        list[i] = other.list[i];
}
template <class elemType>
void ArrayBList<elemType>::clearList() {
    length = 0; //We didn't delete the array, but it doesn't matter. We overwrite the data later
}
template <class elemType>
void ArrayBList<elemType>::retrieveAt(int index, elemType &item) const {
    if (index < 0 || index >= length)
        std::cerr << "The index is out of bounds." << std::endl;
    else
        item = list[index];
}
template <class elemType>
void ArrayBList<elemType>::insertEnd(const elemType &item) {
    if (isFull())
        std::cerr << "The array is full." << std::endl;
    else {
        list[length] = item;
        length++;
    }
}
template <class elemType>
void ArrayBList<elemType>::replaceAt(int index, const elemType &item) {
    if (index < 0 || index >= length) 
        std::cerr << "The index is out of bounds." << std::endl;
    else
        list[index] = item;
}
template <class elemType>
void ArrayBList<elemType>::removeAtIndex(int givenLoc, const elemType &item) {
    if (givenLoc < 0 || givenLoc >= length) 
        std::cerr << "The given location is out of bounds" << std::endl;
    else
        for (int i = givenLoc; i < length; i++) 
            list[i] = list[i + 1];
        length--;
}
template <class elemType>
void ArrayBList<elemType>::insertAtIndex(int givenLoc, const elemType &item) {
    if (givenLoc < 0 || givenLoc > length) //The second comparison is to ensure we don't have any gaps in the list
        std::cerr << "The location is invalid." << std::endl;
    else if (isFull())
        std::cerr << "The array is full." << std::endl;
    else {
        for (int i = length; i > givenLoc; i--) 
            list[i] = list[i - 1];
        list[givenLoc] = item;
        length++;
    }
}
template <class elemType>
bool ArrayBList<elemType>::isItemAtIndexEqual(int givenLoc, const elemType &comparator) const {
    return list[givenLoc] == comparator;
}
template <class elemType>
void ArrayBList<elemType>::print() const {
    assert (list != NULL);
    for (int i = 0; i < length; i++)
        std::cout << list[i] << " ";
    std::cout << std::endl;
}
template <class elemType>
int ArrayBList<elemType>::getListMaxSize() const {
    return maxSize;
}
template <class elemType>
int ArrayBList<elemType>::getListSize() const {
    return length;
}
template <class elemType>
bool ArrayBList<elemType>::isFull() const {
    return (length == maxSize);
}
template <class elemType>
bool ArrayBList<elemType>::isEmpty() const {
    return (length == 0);
}
template <class elemType>
ArrayBList<elemType>::ArrayBList(int maxSize) {
    if (maxSize < 0) {
        maxSize = 100;
        std::cerr << "The size of the array must be positive. Alloting a maximum size of 100 for the array." << std::endl;
    } 
    else
        this -> maxSize = maxSize;
    list = new elemType[maxSize];
    length = 0; 
    assert(list != NULL);
}
template <class elemType>
ArrayBList<elemType>::~ArrayBList() {
    if (list != NULL)
        delete []list;
}