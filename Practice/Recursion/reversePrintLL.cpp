#include <iostream>
using namespace std;
struct nodeType {
    int info;
    nodeType *link;
};
class LinkedList {
    public:
    nodeType *head;
    nodeType *tail;
    int count;
    LinkedList();
    void append(const int &);
    ~LinkedList();
    void printReversell(nodeType *);
    void printRev();
};
LinkedList::LinkedList() {
    count = 0;
    head = tail = NULL;
}
void LinkedList::append(const int &item) {
    nodeType *newNode = new nodeType();
    newNode->info = item;
    newNode->link = NULL;
    if (count == 0)
        head = tail = newNode;
    else {
        tail->link = newNode;
        tail = newNode;
    }
    count++;
}
LinkedList::~LinkedList() {
    nodeType *current = head;
    while (current != NULL) {
        head = head->link;
        delete current;
        current = head;
    }
    count = 0;
}
void LinkedList::printReversell(nodeType *start) {
    if (start != NULL) {
        printReversell(start->link);
        cout << start->info << " ";
    }
}
void LinkedList::printRev() {
    printReversell(head);
}
int main() {
    LinkedList myList;
    for (int i = 0; i < 10; i++)
        myList.append(i);
    myList.printRev();
}