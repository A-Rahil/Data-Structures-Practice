#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Stacks\stacks.h"
//If the stack has 5 items, then the stackTop is also going to be 5
bool equalityTaB(StackArray<int> &s) {
    if (s.isEmpty())
        return true;
    else {
        StackArray<int> q = s;
        int top = q.peak();
        int bottom;
        while (!q.isEmpty()) {
            bottom = q.peak();
            q.pop();
        }
        return (bottom == top);
    }
}

// 5 9 4 9 0