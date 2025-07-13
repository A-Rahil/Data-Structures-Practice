#include "ADTLinkedList.h"
//Copy List method
void LinkedList::copyList(const LinkedList &item) {
    Node *current;
    Node *newNode;
    if (!isEmpty()) 
        initializeList();
    if (item.isEmpty()) {
        initializeList();
    }
    else {
        current = item.head;
        count = item.count;
        head = new Node();
        head->info = current->info;
        head->link = NULL;
        tail = head;
        while (current != NULL) {
            newNode = new Node();
            newNode->info = current->info;
            newNode->link = NULL;
            tail->link = newNode;
            tail = newNode;
            current = current->link;
        }
    }
}
void UnorderedList::deleteNode(const int &item) {
    Node *current, *trailCurrent;
    bool found = false;
    if (isEmpty()) 
        cout << "List is empty" << endl;
    else {
        if (head->info == item) {
            current = head;
            head = head->link;
            if (head == NULL) 
                tail = NULL;
            delete current;
            count--;
        }
        else {
            current = head->link;
            trailCurrent = head;
            while (current != NULL && !found) {
                if (current->info == item) {
                    found = true;
                    trailCurrent->link = current->link;
                    delete current;
                    count--;
                }
                else {
                    trailCurrent = current;
                    current = current->link;
                }
            }
            if (!found)
                cout << "Not found" << endl;
        }
    }
}
void OrderedList::insertFirst(const int &item) {
    Node *current, *trailCurrent;
    Node *newNode = new Node();
    newNode->info = item;
    newNode->link = NULL;
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        current = head;
        trailCurrent = NULL;
        while (current != NULL && current->info < item) {
            trailCurrent = current;
            current = current->link;
        }
        if (trailCurrent == NULL) {
            newNode->link = head;
            head = newNode;
        }
        else {
            newNode->link = trailCurrent->link;
            trailCurrent->link = newNode;
            if (current == NULL) 
                tail = newNode;
            }
        }
    count++;
}