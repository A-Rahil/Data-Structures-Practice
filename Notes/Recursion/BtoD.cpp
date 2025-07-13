#include <iostream>
using namespace std;
void DecToBin(int num, int base) {
    //Either do it iteratively or recursively
    if (num > 0) {
        DecToBin(num / base, base);
        cout << num % base;
    }
    //Can use it for other bases too
}
//Time complexity of logn, and the same space complexity
int sumOfEven(int arr[], int size, int index) {
    if (arr[index] % 2 == 0) 
        return arr[index] + sumOfEven(arr, size, index - 1);
    else {
        return sumOfEven(arr, size, index - 1);
        //Linear recursion problem since we only execute one branch at a time
        //At any time, we are storing three variables
        //Hence, the time and space complexity are both O(n)
    }
}
int main() {

    return 0;
}