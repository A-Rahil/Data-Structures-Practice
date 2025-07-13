#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Queues\queues.cpp"
void printQueue(const QueueArray &q) {
    QueueArray t(q);
    while (!t.isEmpty()) {
        cout << t.front() << " ";
        t.dequeue();
    }
}