#include <iostream>
#include <cassert>
using namespace std;
class QueueArray {
    int queueFront;
    int queueRear;
    int *list;
    int maxQueueSize;
    int count;
    public:
    QueueArray(int = 100);
    bool isEmpty() const;
    bool isFull() const;
    void initializeQueue();
    int front() const;
    int rear() const;
    void enqueue(const int &);
    void dequeue();
    void destroyQueue();
    ~QueueArray();
    //Below methods are practice and implemented in the Practice folder
    void deleteMin();
    void printQueue();
    void reverseQueue();
    void printRev();
    int queueSum();
};
/* Sometimes, with dequeueing and enqueuing, our queue overflows
Here is how it looks like:
AAABBBCCC -> queue with its elements
XXXXXXXCC -> x represents dequeue elements, but the issue is that our queue looks full as our queueBack stayed where it was and queueFront moved backwards
The positions preceeding rear are inaccessible
To fix this, we can have two solutions:
if ((queueRear == maxQueueSize - 1) && queueFront > 0) {
    for (int i = queueFront; i <= queueRear; i++) {
        list[i - queueFront] = list[i];
    }
    queueFront = 0;
    queueRear = count - 1;
}

But this isn't recommended as we have to manually check for this, and shifting the elements down like that is an O(n) operation

*/
QueueArray::~QueueArray() {
    destroyQueue();
}
void QueueArray::destroyQueue() {
    delete [] list;
    count = 0;
}
void QueueArray::dequeue() {
    if (isEmpty())
        cout << "The queue is empty" << endl;
    else {
        queueFront = (queueFront + 1) % maxQueueSize;
        count--;
    }
}
void QueueArray::enqueue(const int &item) {
    if (isFull())
        cout << "The queue is full" << endl;
    else {
        queueRear = (queueRear + 1) % maxQueueSize;
        list[queueRear] = item;
        count++;
    }
}
int QueueArray::rear() const {
    assert(!isEmpty());
    return list[queueRear];
}
int QueueArray::front() const {
    assert(!isEmpty());
    return list[queueFront];
}
void QueueArray::initializeQueue() {
    queueFront = 0;
    queueRear = maxQueueSize - 1;
    count = 0;
}
bool QueueArray::isEmpty() const {
    return (count == 0);
}
bool QueueArray::isFull() const {
    return (count == maxQueueSize);
}
QueueArray::QueueArray(int size) {
    if (size <= 0)
        maxQueueSize = 100;
    else 
        maxQueueSize = size;
    list = new int[maxQueueSize];
    queueFront = 0;
    count = 0;
    queueRear = maxQueueSize - 1;
}