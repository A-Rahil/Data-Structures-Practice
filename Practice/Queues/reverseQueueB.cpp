#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Queues\Queues.cpp"
void reverseQueue(QueueArray &q) {
    QueueArray t = q;
    int size = 0;
    while (!t.isEmpty()) {
        t.dequeue();
        size++;
    }
    int *list = new int[size];
    for (int i = 0; i < size; i++) {
        list[i] = q.front();
        q.dequeue();
    }
    for (int i = size - 1; i >= 0; i--) {
        q.enqueue(list[i]);
    }
    delete []list;
}