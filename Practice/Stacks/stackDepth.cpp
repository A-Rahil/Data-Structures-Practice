#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Stacks\stacks.h"
int stackEDepth(const StackArray<int> &s, const int &item) {
    int depth = 0;
    StackArray<int> t = s;
    while (!t.isEmpty()) {
        if (t.peak() == item) {
            return depth;
        }
        depth++;
        t.pop();
    }
    return -1;
}