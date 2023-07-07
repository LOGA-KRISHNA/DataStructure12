#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
private:
    int stack[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    void push(int element) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
        }
        else {
            top++;
            stack[top] = element;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1; // Return a default value to indicate underflow
        }
        else {
            int element = stack[top];
            top--;
            return element;
        }
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1; // Return a default value to indicate empty stack
        }
        else {
            return stack[top];
        }
    }

    int size() {
        return top + 1;
    }
};

int main() {
    Stack myStack;
    myStack.push(5);
    myStack.push(10);
    myStack.push(15);

    cout << "Size of the stack: " << myStack.size() << endl;
    cout << "Top element of the stack: " << myStack.peek() << endl;

    int popped = myStack.pop();
    cout << "Popped element: " << popped << endl;

    cout << "Size of the stack after popping: " << myStack.size() << endl;
    cout << "Top element of the stack after popping: " << myStack.peek() << endl;

    return 0;
}

