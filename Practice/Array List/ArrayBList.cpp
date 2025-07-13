//Define an Abstract Data Type
//Hiding design details from the implementation
#include <iostream>
#include <cassert>
using namespace std;
template <class elemType> //Generic data type for code-reusability
class ArrayList {
    //Components we need: a pointer to dynamically allocate memory, a counter of elements and a max size
    elemType *list;
    int length;
    int maxSize;
    public:
    bool isEmpty() const;
    bool isFull() const;
    int listSize() const;
    void print() const;
    bool isItemAtEqual(int, const elemType &) const;    //Go to index, check if parameter value is equal or not
    void insertAt(int, const elemType &);   //Push the elements ahead to create space for the needed item, then add it
    void removeAt(int);   //Drag the elements down and overwrite the previous element
    void insertEnd(const elemType &);   //Append to the end
    void replaceAt(int, const elemType &);  //Overwrite the element at the index
    void clearList();   //Set the length to zero
    ~ArrayList();
    ArrayList(int = 100);   //Allocate an array
    ArrayList(const ArrayList &);   //Copy constructor to avoid shallow copies
    const ArrayList& operator=(const ArrayList &);  //Overloaded = operator to avoid shallow copies 
    int SeqSearch(const elemType&) const;   
    void insert(const elemType &);  //If item exists, don't add. If not, then add at the end
    void remove(const elemType &);  //If item doesn't exist, don't delete. If not, search and delete it
};
template <class elemType>
bool ArrayList<elemType>::isEmpty() const {
    return (length == 0);
}
template <class elemType>
bool ArrayList<elemType>::isFull() const {
    return (length == maxSize);
}
template <class elemType>
int ArrayList<elemType>::listSize() const {
    return length;
}
template <class elemType>
void ArrayList<elemType>::print() const {
    assert(list != NULL);
    for (int i = 0; i <  length; i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}
template <class elemType>
bool ArrayList<elemType>::isItemAtEqual(int index, const elemType &item) const {
    return (list[index] == item);
}
template <class elemType>
void ArrayList<elemType>::insertAt(int index, const elemType &item) {
    //Check if the index provided is valid or not
    if (index < 0 || index >= length) {
        cerr << "Invalid index" << endl;
    }
    else {
        if (isFull()) 
            cerr << "Array is full" << endl;
        else {
            for (int i = length; i > index; i--) {  //Form a gap at the provided index, push the elements ahead forward by one index, then add the element at the index
                list[i] = list[i - 1];  //Copying starts from right to left to ensure no data loss
            }
            list[index] = item;
            length++;
        }
    }
}
template <class elemType>
void ArrayList<elemType>::removeAt(int index) {
    //Check if the index is valid or not
    if (index < 0 || index >= length)
        cerr << "Invalid index to delete from" << endl;
    else {
        for (int i = index; i < length - 1; i++) //Start at the provided index, drag the elements down by one index where we override the given index
            list[i] = list[i + 1];  //Stops at length - 1, because the array gets downsized in this operation
        length--;
    }
} 
template <class elemType>
void ArrayList<elemType>::insertEnd(const elemType &item) {
    if (isFull())
        cerr << "List is full" << endl;
    else 
        {
            list[length] = item;    //Simple append method
            length++;
        }
}
template <class elemType>
void ArrayList<elemType>::replaceAt(int index, const elemType &item) {
    if (index < 0 || index >= length) 
        cerr << "Invalid index" << endl;
    else {
        list[index] = item;
    }
}
template <class elemType>
void ArrayList<elemType>::clearList() {
    length = 0;
}
template <class elemType>
ArrayList<elemType>::~ArrayList() {
    clearList();
    delete []list;
    list = NULL;
}
template <class elemType>
ArrayList<elemType>::ArrayList(int size) {
    if (size < 0)
        maxSize = 100;
    else 
        maxSize = size;
    length = 0;
    list = new elemType[maxSize];
    assert(list != NULL);
}
template <class elemType>
ArrayList<elemType>::ArrayList(const ArrayList<elemType> &other) {
    length = other.length;
    maxSize = other.maxSize;
    delete []list;
    list = new elemType[maxSize];
    assert(list != NULL);
    for (int i = 0; i < length; i++) {
        list[i] = other.list[i];
    }
}
template <class elemType>
const ArrayList<elemType>& ArrayList<elemType>::operator=(const ArrayList<elemType> &other) {
    if (this != &other) {
        delete []list;
        length = other.length;
        maxSize = other.maxSize;
        list = new elemType[length];
        assert(list != NULL);
        for (int i = 0; i < length; i++) 
            list[i] = other.list[i];
    }
    return *this;
}
template <class elemType>
int ArrayList<elemType>::SeqSearch(const elemType &item) const{
    for (int i = 0; i < length; i++) {
        if (list[i] == item)
            return i;
    }
    return -1;
}
template <class elemType>
void ArrayList<elemType>::remove(const elemType &item) {
    int locIndex;
    if (length == 0) 
        cerr << "Cannot remove from an empty list" << endl;
    else {
        locIndex = SeqSearch(item); //Search for the element, find its index or if it exists in the array. Then use the removeAt method, with the found index
        if (locIndex == -1) 
            cout << "Item doesn't exist in the list" << endl;
        else 
            removeAt(locIndex);
    }
}
template <class elemType>
void ArrayList<elemType>::insert(const elemType &item) {
    int locIndex;
    if (length == 0) 
        list[length++] = item;
    else if (isFull())
        cerr << "List is full" << endl;
    else {
        locIndex = SeqSearch(item); //If item exists already, then don't add it
        if (locIndex == -1) 
            list[length++] = item;
        else 
            cerr << "Item exists already" << endl;
    }
}