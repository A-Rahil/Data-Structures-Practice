#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Stacks\stacks.h"
int findSecMinimum(const StackArray<int> &s) {
    StackArray<int> t = s;
    int min = t.peak();
    while (!s.isEmpty()) {
        if (t.peak() < min) 
            min = t.peak();
        t.pop();
    }
    int secMin = t.peak();
    t = s;
    while (!t.isEmpty()) {
        if (t.peak() > min && t.peak() < secMin)
            secMin = t.peak();
        t.pop();
    }
    return secMin;
}
