#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "FileHandler.h"


void wyczyscDrzewo(BinarySearchTree& tree) {
    std::string choice = "";

    while (choice != "0" && choice != "1") {
        std::cout << "Czy chcesz wyczyscic drzewo? (1 - Tak, 0 - Nie): ";
        std::cin >> choice;

        if (choice == "1") {
            tree.Clear();
            std::cout << "\nDrzewo zostalo wyczyszczone.\n" << std::endl;
        } else if (choice == "0") {
            std::cout << "\nDrzewo nie zostalo wyczyszczone.\n" << std::endl;
        } else {
            std::cout << "\nBlad! Wprowadz 1, aby wyczyscic drzewo, lub 0, aby nie.\n" << std::endl;
        }
    }
}


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
        std::cout << "7a. Zapisz drzewo do pliku\n";
        std::cout << "7b. Rysuj drzewo do pliku\n";
        std::cout << "8. Wczytaj drzewo z pliku .dat\n";
        std::cout << "9. Wczytaj plik tekstowy z cyfr\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wpisz swoj wybor: ";
        std::cin >> input;

        std::string value;

        if (input == "1") {
            std::cout << "Wprowadz element do dodania: ";
            std::cin >> value; //wprowadzanie liczby przez uzytkownika
            if(value[0] <= '9' && value[0] >='0'){  //program sprawdza, czy jest to liczba lub nie
                tree.Insert(std::stoi(value)); //Jeśli wprowadzona wartość jest liczbą (od 0 do 9), program przekształci wartość w liczbe całkowitą i umieści ją w drzewie
            } else {
                std::cout<< "\n!!! To nie jest liczba !!!\n\n"; //jesli wartosc nie jest liczba wyswietli komunikat i nie doda do drzewa
            }
            
            } else if (input == "2") {
            std::cout << "Wprowadz element do usuniecia: ";
            std::cin >> value; //wprowadzanie liczby przez uzytkownika
            if(value[0] <= '9' && value[0] >='0'){  //program sprawdza, czy jest to liczba lub nie
               tree.Remove(std::stoi(value));    //usuwa liczbe jesli wartość jej jest poprawna
            } else {
                std::cout<< "\n!!! To nie jest liczba !!!\n\n";
            }
        } else if (input == "3") {
            tree.Clear();   
            std::cout << "Drzewo usuniete.\n";
            
        } else if (input == "4") {
            std::cout << "Element do wyszukania: ";
            std::cin >> value; //wprowadzanie liczby przez uzytkownika
             if(value[0] <= '9' && value[0] >='0'){  //program sprawdza, czy jest to liczba lub nie
                std::cout << "\nSciezka do wartosci " + tree.Search(std::stoi(value)) << std::endl; //szuka elementu w drzewie 
            } else {
                std::cout<< "\n!!! To nie jest liczba !!!\n\n";
            }

        } else if (input == "5") {
            std::cout << "Tree: ";
            tree.Display();
            std::cout << "\n";
            
        } else if (input == "6") {
            tree.DisplayTree();
        
       } else if (input == "7a") {
            std::string filename;
            std::cout << "Wpisz nazwe pliku .dat do zapisania: ";
            std::cin >> filename;
            FileHandler::SaveToFile(tree, filename);
            std::cout << "Drzewo zapisane do pliku.\n";
        } else if (input == "8") {
            std::string filename;
            std::cout << "Wpisz nazwe pliku do zaladowania: ";
            std::cin >> filename;
            if (FileHandler::LoadFromFile(tree, filename)) {
                std::cout << "Drzewo zostalo zaladowane z pliku.\n";
            }
        } else if (input == "9") {
            wyczyscDrzewo(tree);
            std::string filename;
            std::cout << "Wpisz nazwe pliku .txt aby zaladowac drzewo: ";
            std::cin >> filename;
            if (FileHandler::LoadFromTextFile(tree, filename)) {
                std::cout << "Drzewo zostalo zaladowane z pliku tekstowego.\n";
            }
            
        } else if (input == "7b"){
             std::string filename = "";
            std::cout << "Wpisz nazwe pliku .txt w ktorym nalezy narysowac drzewo: ";
            std::cin >> filename;
             tree.DisplayTreeToFile(filename + ".txt");
        } else if (input == "0") {
            break;
        }
    }
return 0;
}
