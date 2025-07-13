#include <iostream>
using namespace std;
void deleteByShift(int arr[], int L, int H, int fill) {
    if (L != H) {
        arr[L] = arr[L + 1];
        deleteByShift(arr, L + 1, H, fill);
    }
    else if (L == H)
        arr[H] = fill;
}
int main() {
    int arrElem[6] = {1, 2, 3, 4, 5, 6};
    deleteByShift(arrElem, 0, 5, -1);
    for (int i = 0; i < 6; i++)
        cout << arrElem[i] << " ";
}