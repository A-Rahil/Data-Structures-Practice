#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Queues\queues.cpp"
int sumPositive(const QueueArray &q) {
    QueueArray t(q);
    int sum = 0;
    while (!t.isEmpty()) {
        if (t.front() > 0) 
            sum += t.front();
        t.dequeue();
    }
    return sum;
}