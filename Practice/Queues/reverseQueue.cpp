#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Queues\Queues.cpp"
void QueueArray::reverseQueue() {
    int j = count - 1;
    for (int i = 0; i < count / 2; i++) {
        int temp = list[(queueFront + i) % maxQueueSize];
        list[(queueFront + i) % maxQueueSize] = list[(queueFront + j) % maxQueueSize];
        list[(queueFront + j) % maxQueueSize] = temp;
        j--;
    }
}
int main() {
    QueueArray myQ(6);
    for (int i = 0; i < 6; i++) {
        myQ.enqueue(i);
    }
    myQ.printQueue();
    myQ.reverseQueue();
    myQ.printQueue();
    return 0;
}