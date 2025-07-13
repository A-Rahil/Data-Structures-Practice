#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Stacks\stacks.h"
void print(const StackArray<int> &s) {
    StackArray<int> t = s;
    while (!t.isEmpty()) {
        cout << t.peak() << endl;
        t.pop();
    }
}