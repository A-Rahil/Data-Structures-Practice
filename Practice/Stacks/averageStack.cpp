#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Stacks\stacks.h"
double stackAverage(const StackArray<int> &s) {
    StackArray<int> t = s;
    int sum, count;
    sum = count = 0;
    while (!t.isEmpty()) {
        if (t.peak() > 0) {
            sum += t.peak();
            count++;
        }
        t.pop();
    }
    return sum / count;
}