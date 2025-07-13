#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Queues\queues.cpp"
void QueueArray::printRev() {
    for (int i = count - 1; i >= 0; i--) {
        cout << list[(queueFront + i) % maxQueueSize] << " ";
    }
}