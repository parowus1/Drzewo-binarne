#include "BinarySearchTree.h"
#include <iostream>

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() {
    Clear();
}

void BinarySearchTree::Insert(int value) {
    InsertRecursive(root, value);
}

bool BinarySearchTree::Remove(int value) {
    return RemoveRecursive(root, value);
}

void BinarySearchTree::Clear() {
    ClearRecursive(root);
}
