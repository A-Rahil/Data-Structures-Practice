#include <iostream>
#include <cassert>
using namespace std;
//First create a struct to represent our nodes
struct nodeType {
    int info;
    nodeType *link;
};
//Implement an abstract base class, which would then be derived for Ordered and Unordered classes
class LinkedList {
    protected:
    int count;          //count, head and tail pointers
    nodeType *head;
    nodeType *tail;
    public:
    LinkedList();
    int length() const;
    virtual void insertFirst(const int &) = 0;  //These 4 methods are pure virtual, because their implementations differ based on the type of list we have
    virtual void insertLast(const int &) = 0;   //Also, it is to ensure that this abstract class cannot be instantiated
    virtual void search(int &) = 0;
    virtual void deleteFirst() = 0;
    virtual void deleteLast() = 0;
    void destroyList();
    ~LinkedList();
    void print() const;
    bool isEmpty() const;
    int front() const;
    int back() const;
    bool search(const LinkedList &);
    void copyList(const LinkedList &);
    void initializeList();
    const LinkedList& operator=(const LinkedList &);
};
LinkedList::LinkedList() {  //Initialize and make sure the ptrs don't point anywhere
    count = 0; 
    head = NULL;
    tail = NULL;
}
int LinkedList::length() const {
    return count;
}
void LinkedList::destroyList() {
    nodeType *current = head;   //Assign a temp to track where we are going
    while (head != NULL) {   //As long as head is not NULL, we keep iterating. Head becomes null once list is empty
        head = head->link;  //Move the head forward, delete the current where it is pointing and then reassign current. Strictly this order
        delete current;
        current = head; 
    }
    count = 0;
    tail = NULL;
}
LinkedList::~LinkedList() {
    destroyList();
}
void LinkedList::print() const {
    nodeType *current = head;
    assert (current != NULL);
    while (current != NULL) {
        cout << current->info << " ";
        current = current->link;   //To ensure we don't lose our head
    }
    cout << endl;
}
bool LinkedList::isEmpty() const {
    return (count == 0);
}
int LinkedList::front() const {
    return head->info;
}
int LinkedList::back() const {
    return tail->info;
}
//Will ask the Prof for the rotate method
//Unordered list, non-descending
class UOLinkedList: public LinkedList {
    //Date members inherited as protected, methods inherited as public
    public:
    void insertLast(const int &);
    void insertFirst(const int &);
};
void UOLinkedList::insertLast(const int &item) {
    nodeType *newNode = new nodeType;  //Declare a new node to append, give it the info component
    assert(newNode != NULL);
    newNode->info = item;   //And because it is our last node, have it point to NULL
    newNode->link = NULL;
    if (head == NULL) { //Is the LL empty?
        head = newNode; //If so, point the head and tail to our node
        tail = newNode;
    }
    else {
        tail->link = newNode;  //Tail points to the last element. Make the last point to our new node
        tail = newNode;     //Make the tail point to our new last node
    }
    count++;
}
void UOLinkedList::insertFirst(const int &item) {
    nodeType *newNode = new nodeType;
    assert(newNode != NULL);
    newNode->info = item;
    if (head == NULL) { //Is the LL empty?
        head = newNode; //Point the head and tail at the new node, and make the node point nowhere
        tail = newNode;
        newNode->link = NULL;
    }
    else {
        newNode->link = head; //Make new node point to where head is pointing - to make sure the link remains
        head = newNode; //Make the head point to the new node
    }
    count++;
}
