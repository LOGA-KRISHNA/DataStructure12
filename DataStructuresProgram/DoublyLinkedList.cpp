#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void displayForward() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void displayBackward() {
        Node* current = tail;
        while (current) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Inserting elements at the beginning of the doubly linked list
    dll.insertAtBeginning(5);
    dll.insertAtBeginning(3);
    dll.insertAtBeginning(1);

    // Inserting elements at the end of the doubly linked list
    dll.insertAtEnd(7);
    dll.insertAtEnd(9);
    dll.insertAtEnd(11);

    // Displaying the doubly linked list in forward and backward direction
    std::cout << "Doubly Linked List (Forward): ";
    dll.displayForward();

    std::cout << "Doubly Linked List (Backward): ";
    dll.displayBackward();

    return 0;
}

