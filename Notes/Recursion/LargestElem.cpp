#include <iostream>
using namespace std;
//Finding the largest element in an array:
int largestElem(int arr[], int lowIndex, int uppIndex) {    //pass in array, and lower and upper indices for us to move forward in the array
    if (lowIndex == uppIndex) //Indicates that there is one item in the array - our base case
        return arr[lowIndex];   //Return that element
    else {
        int max = largestElem(arr, lowIndex + 1, uppIndex); //If we have more than one element, then we recursively call the function. Our max becomes the max of the rest of the array
        if (arr[lowIndex] > max)                            //If we trace, we find that the call runs until base case is reached
            max = arr[lowIndex];    //Comparison between the first element and the rest of the array's biggest element
        return max;
    }
}
int main() {
    int newArr[6] = {8, 13, 4, 45, 28, 32};
    cout << largestElem(newArr, 0, 5);
    return 0;
}