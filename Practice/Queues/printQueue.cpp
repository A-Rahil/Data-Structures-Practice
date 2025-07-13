#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Queues\Queues.cpp"
void QueueArray::printQueue() {
    for (int i = 0; i < count; i++) {
        cout << list[(queueFront + i) % maxQueueSize] << " ";
    }
}