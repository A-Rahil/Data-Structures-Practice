#include <iostream>
using namespace std;
//Print a linked list in reverse
void printRev(nodeType *current) {  //this marks the starting point for the LL
    if (current != NULL) {  //We have a hidden base case where the list is empty where we do nothing. This is the recursive case
        printRev(current->link);    //Traverse through the list until we reach the base case where current points to nothing, after which point we
                                    //start backtracking and printing the elements in reverse
        cout << current->info;      //Finally, print the last element
        //We will have multiple calls on the call stack, with each holding its own value for current
        //Because we reach the end, we start backtracking and printing the values of current that each call has 
    }
}
void printLLReverse() { //This is just the helper function because if we were looking to call this in the main, we wouldn't have access to the head
    printRev(head);
    cout << endl;
}