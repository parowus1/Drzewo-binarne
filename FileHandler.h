#include <string>
#include "BinarySearchTree.h"

class FileHandler {
public:
    static void SaveToFile(const BinarySearchTree & tree, const std::string & filename);
    static bool LoadFromFile(BinarySearchTree & tree, const std::string & filename);
    static bool LoadFromTextFile(BinarySearchTree & tree, const std::string & filename);
};

