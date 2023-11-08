#include <iostream>
#include "BinarySearchTree.h"
#include <queue>
#include <string>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>

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

std::string BinarySearchTree::Search(int value) const {
    Node* current = root;
    std::string path = "";
    while (current != nullptr) {
        if (current->data == value) {
            return path;
        } else if (value < current->data) {
            current = current->left;
            path += "0"; 
        } else {
            current = current->right;
            path += "1"; 
        }
    }
    return "Nie znaleziono elementu"; 
}

void BinarySearchTree::Display() const {
    InOrderDisplay(root);
}

void BinarySearchTree::InOrderDisplay(Node* node) const {
    if (node != nullptr) {
        InOrderDisplay(node->left);
        std::cout << node->data << " ";
        InOrderDisplay(node->right);
    }
}

void BinarySearchTree::InsertRecursive(Node*& node, int value) {
    if (node == nullptr) {
        node = new Node(value);
    } else if (value < node->data) {
        InsertRecursive(node->left, value);
    } else {
        InsertRecursive(node->right, value);
    }
}

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

void BinarySearchTree::ClearRecursive(Node*& node) {
    if (node == nullptr) {
        return;
    }
    ClearRecursive(node->left);
    ClearRecursive(node->right);
    delete node;
    node = nullptr;
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
            std::cout<< "404: Drzewo nie istnieje." << std::endl;
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


    void BinarySearchTree::DisplayTreeToFile(const std::string& filename) {
    CollectData();
    if (paths_.empty()){ 
        std::cout << "404: Drzewo nie istnieje." << std::endl;
        return;
    }

    // Otwórz plik do zapisu
    std::ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        std::cerr << "Blad: Nie mozna otworzyc pliku do zapisu." << std::endl;
        return;
    }

    int n = 1, wysokosc = currentLevel_, licznik = 0;
    const int total_width = wysokosc * pow(2, wysokosc);
    for (int i = 0; i < wysokosc; i++) {
        int field_width = total_width / (2 * n);
        for (int j = 0; j < n; j++) {
            ++licznik;

            if (std::stoi(("1" + paths_.front()), 0, 2) == licznik) {
                outputFile << std::setw(field_width) << std::to_string(data_[0]);
                paths_.erase(paths_.begin());
                data_.erase(data_.begin());
            } else {
                outputFile << std::setw(field_width) << "-";
            }

            outputFile << std::setw(field_width) << ' ';
        }
        outputFile << std::endl;
        n *= 2;
    }

    // Zamknij plik po zapisie
    outputFile.close();
}

void BinarySearchTree::Serialize(std::ofstream& file) const {
    SerializeNode(file, root);
}

void BinarySearchTree::SerializeNode(std::ofstream& file, Node* node) const {
    if (node == nullptr) {
        int marker = -1;
        file.write(reinterpret_cast<char*>(&marker), sizeof(int));
    } else {
        file.write(reinterpret_cast<char*>(&node->data), sizeof(int));
        SerializeNode(file, node->left);
        SerializeNode(file, node->right);
    }
}

void BinarySearchTree::Deserialize(std::ifstream& file) {
   // Clear();
    DeserializeNode(file, root);
}

void BinarySearchTree::DeserializeNode(std::ifstream& file, Node*& node) {
    int val;//
    if (file.read(reinterpret_cast<char*>(&val), sizeof(int))) {
        if (val == -1) {
            node = nullptr;
        } else {
            node = new Node(val);
            DeserializeNode(file, node->left);
            DeserializeNode(file, node->right);
        }
    }
}


