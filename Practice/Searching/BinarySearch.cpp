#include <iostream>
using namespace std;
//Always dividing an array into two parts. Algorithmic complexity of O(logn)
//Set a lower and upper boundary that we will be modifying as we go along
//Start at middle (sum of low and high, then divide by 2) of a SORTED array, check if it is the item
//If not the item, then change the lower or upper depending on the if condition
int BSearch(int arr[], int size, const int &item) {
    int low = 0;
    int high = size - 1;
    bool found = false;
    int mid;
    while (low <= high && !found) {
        mid = (high + low ) / 2;
        if (arr[mid] == item)
            found = true;
        else if (arr[mid] < item) 
            low = mid + 1;
        else 
            high = mid - 1;
    }
    if (found)
        return mid;
    else 
        return -1;
}

int BinarySearchRec(int arr[], int item, int low, int high) {
    if (low > high) 
        return -1;
    int mid = (high + low) / 2;
    if (arr[mid] == item) 
        return mid;
    else if (arr[mid] > item) 
        return BinarySearchRec(arr, item, low, mid - 1);
    else 
        return BinarySearchRec(arr, item, mid + 1, high);
}
int main() {
    int newArr[10] = {2, 5, 9, 10, 15, 89, 100, 101, 130, 155};
    /*cout << BSearch(newArr, 10, 89) << endl;
    cout << BSearch(newArr, 10, 2) << endl;
    cout << BSearch(newArr, 10, 130) << endl;
    cout << BSearch(newArr, 10, 9) << endl;*/

    cout << BinarySearchRec(newArr, 89, 0, 9) << endl;
    cout << BinarySearchRec(newArr, 2, 0, 9) << endl;
    cout << BinarySearchRec(newArr, 130, 0, 9) << endl;
    cout << BinarySearchRec(newArr, 9, 0, 9) << endl;
    return 0;
}