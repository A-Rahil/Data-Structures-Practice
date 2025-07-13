#include "Simple Linked Lists/LinkedLists.h"
#include "stacks.h"
void PrintLLBack(nodeType *current) {
    StackArray<int> myStack;
    while (current != NULL) {
        myStack.push(current->info);
        current = current->link;
    }
    while (!myStack.isEmpty()) {
        cout << myStack.peak();
        myStack.pop();
    }
}