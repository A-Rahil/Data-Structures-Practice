//Tower of Hanoi Problem
#include <iostream>
using namespace std;
void TOH(int count, char needle1, char needle2, char needle3) {
    if (count > 1) {
        TOH(count - 1, needle1, needle3, needle2);
        cout << "Moving disk " << count << " from " << needle1 << " to " << needle2 << " using " << needle3 << endl;
        TOH(count - 1, needle2, needle1, needle3);
    }
}