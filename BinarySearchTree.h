#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();
    void Insert(int value);
    bool Remove(int value);
    void Clear();
    bool Search(int value) const;
    void Display() const;

private:
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void InsertRecursive(Node*& node, int value);
    bool RemoveRecursive(Node*& node, int value);
    void ClearRecursive(Node*& node);
    void InOrderDisplay(Node* node) const;
};

#endif
