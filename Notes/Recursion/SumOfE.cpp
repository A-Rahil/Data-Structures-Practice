//Sum of Even elements in an array
#include <iostream>
using namespace std;
int SumOfE(int arr[], int size, int low) {
    if (low == size) {  //The index becomes equal to the size, where we have to stop
        return 0;
    }
    else {
        if (arr[low] % 2 == 0)
            return arr[low] + SumOfE(arr, size, low + 1);   //Add the first even number and then recursively go over the array, incrementing the lower index
        else 
            return SumOfE(arr, size, low + 1);  //Go over the array recursively
    }
}