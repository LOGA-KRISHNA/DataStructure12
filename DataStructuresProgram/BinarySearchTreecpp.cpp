#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
private:
    Node* root;

    Node* insertRec(Node* currentNode, int value) {
        if (currentNode == NULL) {
            return new Node(value);
        }

        if (value < currentNode->data) {
            currentNode->left = insertRec(currentNode->left, value);
        }
        else {
            currentNode->right = insertRec(currentNode->right, value);
        }

        return currentNode;
    }

    bool searchRec(Node* currentNode, int value) {
        if (currentNode == NULL) {
            return false;
        }

        if (value == currentNode->data) {
            return true;
        }

        if (value < currentNode->data) {
            return searchRec(currentNode->left, value);
        }
        else {
            return searchRec(currentNode->right, value);
        }
    }

    void inOrderRec(Node* currentNode) {
        if (currentNode == NULL) {
            return;
        }

        inOrderRec(currentNode->left);
        std::cout << currentNode->data << " ";
        inOrderRec(currentNode->right);
    }

public:
    BST() {
        root = NULL;
    }

    void insert(int value) {
        root = insertRec(root, value);
    }

    bool search(int value) {
        return searchRec(root, value);
    }

    void inOrder() {
        inOrderRec(root);
    }
};

int main() {
    BST bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    bst.inOrder(); // Prints the elements of the BST in ascending order

    std::cout << std::endl;

    std::cout << "Searching for value 40: ";
    if (bst.search(40)) {
        std::cout << "Found" << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }

    std::cout << "Searching for value 90: ";
    if (bst.search(90)) {
        std::cout << "Found" << std::endl;
    }
    else {
        std::cout << "Not found" << std::endl;
    }
	//bst.inOrder();

    return 0;
}

