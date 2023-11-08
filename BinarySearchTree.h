
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

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <string>
#include <vector>

class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void Insert(int value);
    bool Remove(int value);
    void Clear();
    std::string Search(int value) const;    
    void Display() const;
    void CollectData();
    void DisplayTree();
    void Serialize(std::ofstream& file) const;
    void Deserialize(std::ifstream& file);
    void DisplayTreeToFile(const std::string& filename);
    std::vector<int> data_;       


private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    std::vector<std::string> paths_; 
    int currentLevel_ = 0;  
    void SerializeNode(std::ofstream& file, Node* node) const;
    void DeserializeNode(std::ifstream& file, Node*& node);

    Node* root;
    void CollectDataInOrder(Node* node, std::string path);
    void InsertRecursive(Node*& node, int value);
    bool RemoveRecursive(Node*& node, int value);
    void ClearRecursive(Node*& node);
    void InOrderDisplay(Node* node) const;
};

#endif