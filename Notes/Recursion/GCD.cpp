//Find the greatest common divisor of two numbers
//Condition: n is greater than m
#include <iostream>
using namespace std;
int GCD(int n, int m) {
    if (m == 0)
        return m;
    return GCD(n, m % n);
}