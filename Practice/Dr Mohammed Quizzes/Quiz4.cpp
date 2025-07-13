#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Stacks\stacks.h"
//Reverse a stack
void stackReversal(StackArray<int> &myS) {
    StackArray copyS = myS;
    copyS.initializeStack();
    while (!myS.isEmpty()) {
        int top = myS.peak();
        copyS.push(top);
        myS.pop();
    }
    myS = copyS;
}
int main() {
    StackArray<int> newStack(5);
    newStack.push(1);
    newStack.push(2);
    newStack.push(3);
    newStack.push(4);
    newStack.push(5);
    stackReversal(newStack);
    
}