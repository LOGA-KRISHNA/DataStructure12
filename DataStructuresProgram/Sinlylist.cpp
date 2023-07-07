#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void append(int data) {
        Node* new_node = new Node(data);
        if (head == NULL) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void display() {
        if (head == NULL) {
            std::cout << "Linked list is empty." << std::endl;
        } else {
            Node* current = head;
            while (current != NULL) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << "nullptr" << std::endl;
        }
    }

    void deleteNode(int data) {
        if (head == NULL) {
            std::cout << "Linked list is empty." << std::endl;
            return;
        }

        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != NULL) {
            if (current->next->data == data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }

        std::cout << "Node with data " << data << " not found." << std::endl;
    }
};

int main() {
    LinkedList myList;
    myList.append(5);
    myList.append(10);
    myList.append(15);
    myList.display();  // Output: 5 -> 10 -> 15 -> nullptr

    myList.deleteNode(10);
    myList.display();  // Output: 5 -> 15 -> nullptr

    return 0;
}

