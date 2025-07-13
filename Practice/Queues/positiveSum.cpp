#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Queues\queues.cpp"
int QueueArray::queueSum() {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        if (list[(queueFront + i) % maxQueueSize] > 0)
            sum += list[(queueFront + i) % maxQueueSize];
    }
    return sum;
}