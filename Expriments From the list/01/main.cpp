#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insertRecursive(Node* root, int key) {
    if (!root)
        return new Node(key);

    if (key < root->data)
        root->left = insertRecursive(root->left, key);
    else if (key > root->data)
        root->right = insertRecursive(root->right, key);

    return root;
}

Node* insertIterative(Node* root, int key) {
    Node* newNode = new Node(key);
    if (!root)
        return newNode;
    Node* current = root;
    Node* parent = nullptr;
    while (current) {
        parent = current;
        if (key < current->data)
            current = current->left;
        else if (key > current->data)
            current = current->right;
        else
            return root;
    }

    if (key < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int choice, value;
    while (true) {
        cout << "\n1. Insert (Recursive)\n2. Insert (Iterative)\n3. Display (Inorder)\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 4)
            break;
        cout << "Enter value to insert: ";
        cin >> value;
        if (choice == 1)
            root = insertRecursive(root, value);
        else if (choice == 2)
            root = insertIterative(root, value);
        else
            cout << "Invalid choice!";
    }
    cout << "Inorder Traversal: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}