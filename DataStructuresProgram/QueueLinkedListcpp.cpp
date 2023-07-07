#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int element) {
        data = element;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int element) {
        Node* newNode = new Node(element);
        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow" << endl;
            return -1; // Return a default value to indicate underflow
        }
        else {
            int element = front->data;
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
            return element;
        }
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1; // Return a default value to indicate empty queue
        }
        else {
            return front->data;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue myQueue;
    myQueue.enqueue(5);
    myQueue.enqueue(10);
    myQueue.enqueue(15);

    cout << "Front element of the queue: " << myQueue.peek() << endl;

    int dequeued = myQueue.dequeue();
    cout << "Dequeued element: " << dequeued << endl;

    cout << "Front element of the queue after dequeue: " << myQueue.peek() << endl;

    return 0;
}

