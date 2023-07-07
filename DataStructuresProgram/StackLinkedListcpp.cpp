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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int element) {
        Node* newNode = new Node(element);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow" << endl;
            return -1; // Return a default value to indicate underflow
        }
        else {
            int element = top->data;
            Node* temp = top;
            top = top->next;
            delete temp;
            return element;
        }
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value to indicate empty stack
        }
        else {
            return top->data;
        }
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Top element of the stack: " << myStack.peek() << endl;

    int popped = myStack.pop();
    cout << "Popped element: " << popped << endl;

    cout << "Top element of the stack after popping: " << myStack.peek() << endl;

    return 0;
}

