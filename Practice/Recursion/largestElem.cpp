#include <iostream>
//Function to determine the largest element in an array
int largestElem(int arr[], int lowInd, int highInd) {
    int max;
    if (lowInd == highInd)
        return arr[lowInd];
    else {
        max = largestElem(arr, lowInd + 1, highInd);
        if (max < arr[lowInd])
            return arr[lowInd];
        else 
            return max;
    }
}
int main() {
    int testArr[10] = {8, 91, 43, 58, 92, 82, 111, 68, 10, 21};
    std::cout << largestElem(testArr, 0, 9);
    return 0;
}