#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
class StackADT {
public:
    virtual void pop() = 0;
    virtual T peak() const = 0;
    virtual void push(T) = 0;
    virtual bool isFull() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void initializeStack() = 0;
    virtual ~StackADT() {}
};

template <typename T>
class StackArray : public StackADT<T> {
private:
    int stackTop;
    int maxStackSize;
    T* list;

    void copyStack(const StackArray<T>& other);

public:
    StackArray(int size = 100);
    StackArray(const StackArray<T>& other);
    ~StackArray();
    const StackArray<T>& operator=(const StackArray<T>& other);

    void initializeStack();
    bool isEmpty() const;
    bool isFull() const;
    T peak() const;
    void pop();
    void push(T item);
};

template <typename T>
StackArray<T>::StackArray(int size) {
    if (size <= 0)
        maxStackSize = 100;
    else
        maxStackSize = size;
    stackTop = 0;
    list = new T[maxStackSize];
}

template <typename T>
StackArray<T>::StackArray(const StackArray<T>& other) {
    list = nullptr;
    copyStack(other);
}

template <typename T>
StackArray<T>::~StackArray() {
    delete[] list;
}

template <typename T>
const StackArray<T>& StackArray<T>::operator=(const StackArray<T>& other) {
    if (this != &other)
        copyStack(other);
    return *this;
}

template <typename T>
void StackArray<T>::copyStack(const StackArray<T>& other) {
    delete[] list;
    maxStackSize = other.maxStackSize;
    stackTop = other.stackTop;
    list = new T[maxStackSize];
    for (int i = 0; i < stackTop; i++)
        list[i] = other.list[i];
}

template <typename T>
void StackArray<T>::initializeStack() {
    stackTop = 0;
}

template <typename T>
bool StackArray<T>::isEmpty() const {
    return (stackTop == 0);
}

template <typename T>
bool StackArray<T>::isFull() const {
    return (stackTop == maxStackSize);
}

template <typename T>
T StackArray<T>::peak() const {
    assert(stackTop != 0);
    return list[stackTop - 1];
}

template <typename T>
void StackArray<T>::pop() {
    if (isEmpty())
        cout << "Cannot delete from an empty stack" << endl;
    else
        stackTop--;
}

template <typename T>
void StackArray<T>::push(T item) {
    if (isFull())
        cout << "The stack is full" << endl;
    else
        list[stackTop++] = item;
}
