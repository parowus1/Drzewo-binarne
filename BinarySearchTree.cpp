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
    node = nullptr;#include <iostream>
#include <string>
#include "BinarySearchTree.h"


int main() {
    BinarySearchTree tree;
    std::string input;
    bool running = true;

    while (running) {
        std::cout << "\nMenu Binarnego Drzewa:\n";
        std::cout << "1. Dodaj element\n";
        std::cout << "2. Usun element\n";
        std::cout << "3. Usun cale drzewo\n";
        std::cout << "4. Szukaj elementu\n";
        std::cout << "5. Wyswietl inorder drzewa\n";
        std::cout << "6. Narysuj drzewo\n";
        std::cout << "7. Zapisz drzewo do pliku\n";
        std::cout << "8. Wczytaj drzewo z pliku\n";
        std::cout << "9. Wczytaj plik tekstowy z cyfer\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wpisz swoj wybor: ";
        std::cin >> input;

        std::string value;

        if (input == "1") {
            std::cout << "Wprowadz element do dodania: ";
            std::cin >> value;
            if(value[0] <= '9' && value[0] >='0'){
                tree.Insert(std::stoi(value));
            } else {
                std::cout<< "\n!!! To nie jest liczba !!!\n\n";
            }
            
            } else if (input == "2") {
            std::cout << "Wprowadz element do usuniecia: ";
            std::cin >> value;
            if(value[0] <= '9' && value[0] >='0'){
               tree.Remove(std::stoi(value));
            } else {
                std::cout<< "\n!!! To nie jest liczba !!!\n\n";
            }
        } else if (input == "3") {
            tree.Clear();
            std::cout << "Drzewo usuniete.\n";
        } else if (input == "5") {
            std::cout << "Tree: ";
            tree.Display();
            std::cout << "\n";
        }else if (input == "4") {
            std::cout << "Element do wyszukania: ";
            std::cin >> value;

             if(value[0] <= '9' && value[0] >='0'){
                std::cout << (tree.Search(std::stoi(value)) ? "\nZnaleziono element \n" : "\nNie znaleziono elementu\n");
            } else {
                std::cout<< "\n!!! To nie jest liczba !!!\n\n";
            }

        } else if (input == "0"){
            break;
  ////

            
        }else {
            std::cout << "\n!!! Wprowadzono niewlasciwe dane !!!\n\n";
        }
        
    }#include <iostream>
#include <string>
#include "BinarySearchTree.h"


int main() {
    BinarySearchTree tree;
    std::string input;
    bool running = true;

    while (running) {
        std::cout << "\nMenu Binarnego Drzewa:\n";
        std::cout << "1. Dodaj element\n";
        std::cout << "2. Usun element\n";
        std::cout << "3. Usun cale drzewo\n";
        std::cout << "4. Szukaj elementu\n";
        std::cout << "5. Wyswietl inorder drzewa\n";
        std::cout << "6. Narysuj drzewo\n";
        std::cout << "7. Zapisz drzewo do pliku\n";
        std::cout << "8. Wczytaj drzewo z pliku\n";
        std::cout << "9. Wczytaj plik tekstowy z cyfer\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wpisz swoj wybor: ";
        std::cin >> input;

        std::string value;

        if (input == "1") {
            std::cout << "Wprowadz element do dodania: ";
            std::cin >> value;
            if(value[0] <= '9' && value[0] >='0'){
                tree.Insert(std::stoi(value));
            } else {
                std::cout<< "\n!!! To nie jest liczba !!!\n\n";
            }
            
            } else if (input == "2") {
            std::cout << "Wprowadz element do usuniecia: ";
            std::cin >> value;
            if(value[0] <= '9' && value[0] >='0'){
               tree.Remove(std::stoi(value));
            } else {
                std::cout<< "\n!!! To nie jest liczba !!!\n\n";
            }
        } else if (input == "3") {
            tree.Clear();
            std::cout << "Drzewo usuniete.\n";
        } else if (input == "5") {
            std::cout << "Tree: ";
            tree.Display();
            std::cout << "\n";
        }else if (input == "4") {
            std::cout << "Element do wyszukania: ";
            std::cin >> value;

             if(value[0] <= '9' && value[0] >='0'){
                std::cout << (tree.Search(std::stoi(value)) ? "\nZnaleziono element \n" : "\nNie znaleziono elementu\n");
            } else {
                std::cout<< "\n!!! To nie jest liczba !!!\n\n";
            }

        } else if (input == "0"){
            break;
  ////

            
        }else {
            std::cout << "\n!!! Wprowadzono niewlasciwe dane !!!\n\n";
        }
        
    }
}
//wyświetlenie 
void BinarySearchTree::InOrderDisplay(Node* node) const {
    if (node != nullptr) {
        InOrderDisplay(node->left);
        std::cout << node->data << " ";
        InOrderDisplay(node->right);
    }
}

        
