//Most basic type of search where we start at the first element and continue our search, terminating when we find our element of interest
#include <iostream>
using namespace std;
int seqeuentialSearch(const int &item, int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == item) 
            return i;
    }
    return -1;
}
int sequentialSeachRec(int arr[], int size, int start, int item) {
    if (start == size)
        return -1;
    if (arr[start] == item)
        return start;
    else
        return sequentialSeachRec(arr, size, start + 1, item);
}
int main() {
    int arrNum[10] = {3, 6, 7, 1, 89, 32, 2, 31, 45, 10};
    cout << seqeuentialSearch(89, arrNum, 10) << endl;
    cout << seqeuentialSearch(31, arrNum, 10) << endl;
    cout << seqeuentialSearch(0, arrNum, 10) << endl;
    return 0;
}