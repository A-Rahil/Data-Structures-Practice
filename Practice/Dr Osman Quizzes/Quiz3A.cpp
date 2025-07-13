#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Stacks\stacks.h"
//StackTop indicates the index of the in-bound element that will be added
//Indices start from 0, and hence are 1 less than the number of elements
//Hence, the stackTop member variable here represents the count too
bool search(StackArray<int> &myStack, const int &item) {
    if (!myStack.isEmpty()) {
        int top = myStack.peak();
        myStack.pop();
        if (top == item) 
            return true;
        bool found = search(myStack, item);
        myStack.push(top);
        return found;
    }
    else 
        return false;  
}
bool search(StackArray<int> &myStack, const int &item) {
    StackArray<int> copyStack = myStack;
    if (copyStack.isEmpty())
        return false;
    else {
        int top = copyStack.peak();
        if (top == item)
            return true;
        copyStack.pop();
        bool found = search(copyStack, item);
        return found;
    }
}

bool isFrontEqualBack(const QueueArray &q) {
    if (q.isEmpty()) 
        return true;
    return (q.front() == q.back());
}

//b. 2 16 8