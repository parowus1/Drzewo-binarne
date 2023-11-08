#include "FileHandler.h"
#include <fstream>
#include <string>
#include <iostream>

void FileHandler::SaveToFile(const BinarySearchTree& tree, const std::string& filename) {
    std::ofstream file(filename + ".dat", std::ios::binary);
    if (file.is_open()) {
        tree.Serialize(file);
        file.close();
    } else {
        std::cerr << "Blad: Nie mozna otworzyc pliku do odczytu." << std::endl;
    }
}

bool FileHandler::LoadFromFile(BinarySearchTree& tree, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        tree.Deserialize(file);
        file.close();
        return true; 
    } else {
        std::cerr << "Blad: Nie mozna otworzyc pliku do odczytu." << std::endl;
        return false;
    }
}

bool FileHandler::LoadFromTextFile(BinarySearchTree& tree, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
       // tree.Clear();
        int value;
        while (file >> value) {
            tree.Insert(value);
        }
        return true; 
    } else {
        std::cerr << "Blad: Nie mozna otworzyc pliku do odczytu." << std::endl;
        return false;
    }
}



