#include <iostream>
using namespace std;
void DecToBin(int n, int b) {
    if (n > 0) {
        DecToBin(n / b, b); //It makes a call stack that grows until the bottom is reached where n is 0
        cout << n % b;  //Once we exit the call stack, we start printing the values, working backwards
    }
}