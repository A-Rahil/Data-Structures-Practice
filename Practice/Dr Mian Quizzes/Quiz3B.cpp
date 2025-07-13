#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Stacks\stacks.h"

//1a. 6
//1b. 6


int sumOfStackE(const StackArray<int> &aStack) {
    StackArray<int> copyStack = aStack;
    int sum = 0;
    while (!copyStack.isEmpty()) {
        sum += copyStack.peak();
        copyStack.pop();
    }
    return sum;
}
//Non member function that sums the value in the stack
int main() {
    StackArray<int> myStack(4);
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);
    myStack.push(20);
    cout << "Sum of elements: " << sumOfStackE(myStack) << endl;
    return 0;
}