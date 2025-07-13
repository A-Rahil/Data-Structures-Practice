//If a number is a prime number or not
#include <iostream>
using namespace std;
bool isPrime(int n, int inc) {
    if (n <= 1)
        return false;
    if (n % inc == 0)
        return false;
    if (inc * inc > n)  //Stop the search when i is greater than square root of n as we will not find a divisor beyond that
        return true;
    return isPrime(n, inc + 1);
}