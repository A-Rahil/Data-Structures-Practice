//An intro to Linked List vs. Arrays
/*
Arrays: Data stored in consecutive blocks of memory. Reading from an index is instantaneous. Adding or removing is slow
Linked Lists: Data stored anywhere, with references to next point stored. Reading is slow. Adding or removing is fast
*/
#include <iostream>
#include <cassert>
using namespace std;
//Node structure:
struct node {
    int info;
    node *link; //Pointer to next node. Note that we cannot say node link; as that fundamentally doesn't work or make sense
};
//Using the node, we build an Abstract Data Type. This is a simple list, or unordered. We can build upon it to have sorted lists with its own methods
class LinkedList {
    node *head;
    node *tail;
    int count;
    public:
    void print() const; //Traverse the list and print its component
    int length() const;
    void insertLast(const int &);   //Append to either an empty list or one with elements
    void destroyList(); //We execute the deletion when wanted
    ~LinkedList();  //Done by the compiler when the object goes out of scope
    LinkedList();
};
void LinkedList::print() const {
    node *current = head;
    while (current != NULL) {
        cout << current->info << " ";  //Get the info from the node that current is pointing to
        current = current->link;    //Make current point to the next node
    }
    cout << endl;
}
int LinkedList::length() const {
    return count;
}
void LinkedList::insertLast(const int &item) {
    node *elem = new node();
    assert(elem != NULL);   //Always write an assertion after dynamic memory allocation
    elem->info = item;
    elem->link = NULL;
    //Check for a few edge cases
    //Is the list empty or not?
    if (head == NULL) {
        head = elem;    //Both the head and tail will point to the same location since there is only one node
        tail = elem;
    }
    else {
        tail->link = elem;  //Access the element where tail points, take its pointer and point it to our new last node
        tail = elem;
    }
    count++;
}
void LinkedList::destroyList() {
    node *temp;
    while (head != NULL) {
        temp = head;    //Assign a temp tracker to go alongside our head. It does the deletion, while our head progresses forward till the end
        head = head->link;
        delete temp;
    }
    tail = NULL;
    count = 0;
}
LinkedList::~LinkedList() {
    destroyList();
}
LinkedList::LinkedList() {
    count = 0;
    head = NULL;
    tail = NULL;
}