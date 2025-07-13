#include "C:\Users\ahmra\Documents\Uni\Semester 3.5 - UoS\Data Structures\Notes\Queues\queues.cpp"
//Member function that deletes the min value
void QueueArray::deleteMin() {
    int min = list[queueFront];
    int minIndex = queueFront;
    for (int i = 0; i < count; i++) {
        if (list[(queueFront + i) % maxQueueSize] < min) {
            min = list[(queueFront + i) % maxQueueSize];
            minIndex = (queueFront + i) % maxQueueSize;
        }
    }
    for (int i = minIndex; i != queueRear; i = (i + 1) % maxQueueSize) {
        list[i] = list[(i + 1) % maxQueueSize];
    }
    count--;
    queueRear--;
    if (queueRear == -1)
        queueRear = maxQueueSize - 1;
}
int main() {
    QueueArray myQ(5);
    myQ.enqueue(10);
    myQ.enqueue(13);
    myQ.enqueue(9);
    myQ.enqueue(7);
    myQ.enqueue(15);
    myQ.deleteMin();
    for (int i = 0; i < 4; i++) {
        cout << myQ.front() << " ";
        myQ.dequeue();
    }
}