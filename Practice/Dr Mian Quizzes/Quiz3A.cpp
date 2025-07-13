//Tracing question
//Output: 
/*
y = 9
x = 3
7
13 
4
7
*/

//Non member function taht returns the sum of +ve elements
int positiveSum(const QueueArray &q) {
    QueueArray c(q);
    int sum = 0;
    while (!c.isEmpty()) {
        if (t.front() > 0) 
            sum += t.front();
        t.dequeue();
    }
    return sum;
}