#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

//czyszczenie
BinarySearchTree::~BinarySearchTree() {
    Clear();
}
//dodanie
void BinarySearchTree::Insert(int value) {
    InsertRecursive(root, value);
}
//usunięcie
bool BinarySearchTree::Remove(int value) {
    return RemoveRecursive(root, value);
}

void BinarySearchTree::Clear() {
    ClearRecursive(root);
}
//przeszukiwanie drzewa
bool BinarySearchTree::Search(int value) const {
    Node* current = root;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        } else if (value < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return false;
}


//wyświetlenie
void BinarySearchTree::Display() const {
    InOrderDisplay(root);
    std::cout << std::endl;
}//zbyteczne



//binarne zapisywanie
        void BinarySearchTree::InsertRecursive(Node*& node, int value) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (value < node->data) {
        InsertRecursive(node->left, value);
    } else {
        InsertRecursive(node->right, value);
    }
}
// binarne usuwanie
bool BinarySearchTree::RemoveRecursive(Node*& node, int value) {
    if (node == nullptr) {
        return false;
    }
    if (value < node->data) {
        return RemoveRecursive(node->left, value);
    } else if (value > node->data) {
        return RemoveRecursive(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node* minRight = node->right;
            while (minRight->left != nullptr) {
                minRight = minRight->left;
            }
            node->data = minRight->data;
            RemoveRecursive(node->right, minRight->data);
        }
        return true;
    }
}
//binarne czyszczenie
void BinarySearchTree::ClearRecursive(Node*& node) {
    if (node == nullptr) {
        return;
    }
    ClearRecursive(node->left);
    ClearRecursive(node->right);
    delete node;
    node = nullptr;
}
//wyświetlenie 
void BinarySearchTree::InOrderDisplay(Node* node) const {
    if (node != nullptr) {
        InOrderDisplay(node->left);
        std::cout << node->data << " ";
        InOrderDisplay(node->right);
    }
}

        
///