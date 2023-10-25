#include <iostream>
#include "BinarySearchTree.h"
#include <queue>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>

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


//wyświetlenie drzewa
void BinarySearchTree::Display() const {
    InOrderDisplay(root);
    std::cout << std::endl;
}//zbyteczne



//rekurencyjne wstawianie nowego elementu do drzewa
        void BinarySearchTree::InsertRecursive(Node*& node, int value) {
    if (node == nullptr) { //sprawdza czy drzewo jest puste lub czy jesteśmy na końcu drzewa
        node = new Node(value);
    } else if (value < node->data) { //jeśli wartość którą dodajemy jest mniejsza od tej znajdującej się w drzewie, to zostaje dodana do lewego poddrzewa i na odwrót
        InsertRecursive(node->left, value); 
    } else {
        InsertRecursive(node->right, value); 
    }
}
// rekurencyjne usuwanie elementu z drzewa
bool BinarySearchTree::RemoveRecursive(Node*& node, int value) {
    if (node == nullptr) {
        return false; //jeśli drzewo jest puste to kończy działanie
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
//rekurencyjne usuwanie wszystkich węzłów w drzewie
void BinarySearchTree::ClearRecursive(Node*& node) {
    if (node == nullptr) {
        return;
    }
    ClearRecursive(node->left);  //najpierw usuwa węzły z lewego poddrzewa, a następnie z prawego poddrzewa
    ClearRecursive(node->right); 
    delete node;
    node = nullptr;
}
//wyświetlenie rekurencyjnego drzewa
void BinarySearchTree::InOrderDisplay(Node* node) const {
    if (node != nullptr) {
        InOrderDisplay(node->left); //przeszukujemy lewe poddrzewo drzewa, zostaną wyświetlone wszystkie wartości w uporządkowany sposób
        std::cout << node->data << " ";
        InOrderDisplay(node->right); //przeszukujemy prawe poddrzewo drzewa, zostaną wyświetlone wszystkie wartości w uporządkowany sposób
    }
}

void BinarySearchTree::CollectData()  {
        if (root == nullptr) {
            return;
        }

        std::queue<std::pair<Node*, int>> nodeQueue;
        nodeQueue.push(std::make_pair(root, 0)); 
        int currentLevel = -1;

        std::queue<std::pair<Node*, std::string>> pathQueue;
        pathQueue.push(std::make_pair(root, "")); 

        while (!nodeQueue.empty()) {
            Node* current = nodeQueue.front().first;
            int level = nodeQueue.front().second;
            nodeQueue.pop();

            std::string path = pathQueue.front().second;
            pathQueue.pop();

            if (level != currentLevel) {
                currentLevel_ = level; 
            }

            if (current != nullptr) {
                data_.push_back(current->data);
                paths_.push_back(path);
            }

            if (current != nullptr) {
                if (current->left != nullptr) {
                    nodeQueue.push(std::make_pair(current->left, level + 1));
                    pathQueue.push(std::make_pair(current->left, path + "0"));
                } else {
                    nodeQueue.push(std::make_pair(nullptr, level + 1));
                    pathQueue.push(std::make_pair(nullptr, path + "0"));
                }

                if (current->right != nullptr) {
                    nodeQueue.push(std::make_pair(current->right, level + 1));
                    pathQueue.push(std::make_pair(current->right, path + "1"));
                } else {
                    nodeQueue.push(std::make_pair(nullptr, level + 1));
                    pathQueue.push(std::make_pair(nullptr, path + "1"));
                }
            }
        }
    }

     void BinarySearchTree::DisplayTree() {
        CollectData();
        if (paths_.empty()){ 
            std::cout<< "404: Tree doesn't exist." << std::endl;
            return;
        }
        std::cout << std::endl;
        int n = 1, wysokosc = currentLevel_, licznik = 0;;
        const int total_width = wysokosc * pow(2, wysokosc);
        for (int i = 0; i < wysokosc; i++) {
            int field_width = total_width / (2 * n);
            for (int j = 0; j < n; j++) {
                ++licznik;

                if (std::stoi(("1" + paths_.front()), 0, 2) == licznik) {
                    std::cout << std::setw(field_width) << std::to_string(data_[0]);
                    paths_.erase(paths_.begin());
                    data_.erase(data_.begin());
                } else {
                    std::cout << std::setw(field_width) << "-";
                }

                std::cout << std::setw(field_width) << ' ';
            }
            std::cout << std::endl;
            n *= 2;
        }
    }
        
