//A more general LinkedList ADT that can be derived to either be sorted or unsorted, with each having its own methods
#include <iostream>
#include <cassert>
using namespace std;
struct Node {
    int info;
    Node *link;
};
//Abstract base class for a more general list
//You can ofcourse make this a generic data type by using templates
class LinkedList {
    protected:
    Node *head;
    Node *tail;
    int count;
    private:
    void copyList(const LinkedList &);
    public:
    void print() const;
    int getLength() const;
    bool isEmpty() const;
    void initializeList();
    void destroyList();
    int front() const;
    int back() const;
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList &);
    const LinkedList& operator=(const LinkedList &);
    virtual bool search(const int &) = 0;
    virtual void insertFirst(const int &) = 0;
    virtual void insertLast(const int &) = 0;
    virtual void deleteNode(const int &) = 0;
};
void LinkedList::print() const {
    Node *current = head;
    while (current != NULL) {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}
int LinkedList::getLength() const {
    return count;
}
void LinkedList::initializeList() {
    destroyList();
}
bool LinkedList::isEmpty() const {
    return (count == 0);
}
void LinkedList::destroyList() {
    Node *current;  
    while (head != NULL) {
        current = head;
        head = head->link;
        delete current;
    }
    tail = NULL;
    count = 0;
}
int LinkedList::front() const {
    assert(head != NULL);   //Important, you have to make sure that the list isn't empty
    return head->info;
}
int LinkedList::back() const {
    assert(tail != NULL);   //Important again
    return tail->info;
}
LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
    count = 0;
}
LinkedList::~LinkedList() {
    destroyList();
}
void LinkedList::copyList(const LinkedList &other) {
    Node *newNode;
    Node *current;
    if (head != NULL) { //If our list is not empty, destroy it and reinitialize it
        destroyList();
    }
    if (other.head == NULL) {   //If the other list is empty, then make ours empty too
        head = NULL;
        tail = NULL;
        count = 0;
    }
    else {
        current = other.head;
        count = other.count;
        head = new Node();
        head->info = current->info;
        head->link = NULL;
        tail = head;
        current = current->link;
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
LinkedList::LinkedList(const LinkedList &other) {
    head = NULL;
    copyList(other);
}
const LinkedList &LinkedList::operator=(const LinkedList &other) {
    copyList(other);
    return *this;
}

//Unordered Linked List 
class UnorderedList: public LinkedList {
    public:
    bool search(const int &);
    void insertFirst(const int &);
    void insertLast(const int &);
    void deleteNode(const int &);
};
bool UnorderedList::search(const int &item) {
    if (isEmpty())
        return false;
    Node *current = head;
    while (current != NULL) {
        if (current->info == item)
            return true;
        else {
            current = current->link;
        }
    }
    return false;
}
void UnorderedList::insertFirst(const int &item) {
    Node *newNode = new Node();
    assert(newNode != NULL);
    newNode->info = item;
    newNode->link = NULL;
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->link = head;
        head = newNode;
    }
    count++;
}
void UnorderedList::insertLast(const int &item) {
    Node *newNode = new Node();
    assert(newNode != NULL);
    newNode->info = item;
    newNode->link = NULL;
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->link = newNode;
        tail = newNode;
    }
    count++;
}
void UnorderedList::deleteNode(const int &item) {
    Node *current;
    Node *currentTrail;
    if (isEmpty()) {
        cout << "List is empty" << endl;
    }
    else {
        if (head->info == item) {
            current = head;
            head = head->link;
            count--;
            if (head == NULL) {
                tail = NULL;
            }
            delete current;
        }
        else {
            bool found = false;
            currentTrail = head;
            current = head->link;
            while (current != NULL && !found) {
                if (current->info != item) {
                    currentTrail = current;
                    current = current->link;
                }
                else {
                    found = true;
                }
            }
            if (found) {
                currentTrail->link = current->link;
                count--;
                if (tail == current) {
                    tail = currentTrail;
                }
                delete current;
            }
            else {
                cout << "The item was not found" << endl;
            }
        }
    }
}

//Ordered Linked List
class OrderedList: public LinkedList {
    bool search(const int &);
    void insert(const int &);
    void deleteNode(const int &);
    void insertFirst(const int &);
};
bool OrderedList::search(const int &item) {
    Node *current = head;
    if (isEmpty()) 
        return false;
    else {
        while (current != NULL) {
            if (current->info == item) 
                return true;
            else if (current->info > item)
                return false;
            else 
                current = current->link;
        }
        return false;
    }
}
void OrderedList::insert(const int &item) {
    Node *newNode = new Node();
    newNode->info = item;
    newNode->link = NULL;
    bool found;
    Node *current;
    Node *trailCurrent;
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    }
    else {
        current = head;
        found = false;
        while(current != NULL && !found) {
            if (current->info >= item) 
                found = true;
            else {
                trailCurrent = current;
                current = current->link;
            }
        }
        if (current == head) {
            newNode->link = head;
            head = newNode;
        }
        else {
            trailCurrent->link = newNode;
            newNode->link = current;
            if (current == NULL) {
                tail = newNode;
            }
        }
    }
    count++;
}
void OrderedList::deleteNode(const int &item) {
    Node *current = head, *trail = NULL;
    bool found = false;
    if (isEmpty()) 
        cerr << "Empty list";
    else {
        if (head->info == item) {
            head = head->link;
            delete current;
            if (head == NULL) 
                tail = NULL;
            count--;
        }
        else {
            trail = current;
            current = current->link;
            while (current != NULL && !found) {
                if (current->info == item) {
                    trail->link = current->link;
                    delete current;
                    if 
                }
            }
        }
    }
}