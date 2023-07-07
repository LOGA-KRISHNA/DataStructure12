#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the queue

class Queue {
private:
    int queue[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enqueue(int element) {
        if (rear == MAX_SIZE - 1) {
            cout << "Queue Overflow" << endl;
        }
        else {
            if (front == -1) {
                front = 0;
            }
            rear++;
            queue[rear] = element;
        }
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue Underflow" << endl;
            return -1; // Return a default value to indicate underflow
        }
        else {
            int element = queue[front];
            front++;
            return element;
        }
    }

    int peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty" << endl;
            return -1; // Return a default value to indicate empty queue
        }
        else {
            return queue[front];
        }
    }

    int size() {
        return rear - front + 1;
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);

    cout << "Size of the queue: " << myQueue.size() << endl;
    cout << "Front element of the queue: " << myQueue.peek() << endl;

    //int dequeued = myQueue.dequeue();
    cout << "Dequeued element: " << myQueue.dequeue() << endl;

    cout << "Size of the queue after dequeue: " << myQueue.size() << endl;
    cout << "Front element of the queue after dequeue: " << myQueue.peek() << endl;

    return 0;
}

