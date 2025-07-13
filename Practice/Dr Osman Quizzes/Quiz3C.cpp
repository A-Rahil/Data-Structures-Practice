#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Stacks\stacks.h"
void clearBottomRec(StackArray<int> &s) {
    if (s.isEmpty())
        return;
    int top = s.peak();
    s.pop();
    if (!s.isEmpty()) {
        clearBottomRec(s);
        s.push(top);
    }
}

//Duplicate back
void duplicateBack(QueueArray &q) {
    assert(!q.isEmpty());
    q.enqueue(q.back());
}