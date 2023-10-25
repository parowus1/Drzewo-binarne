#include <iostream>
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
                std::cout << (tree.Search(std::stoi(value)) ? "\nZnaleziono element \n" : "\nNie znaleziono elementu\n"); //szuka elementu w drzewie 
            } else {
                std::cout<< "\n!!! To nie jest liczba !!!\n\n";
            }

        } else if (input == "5") {
            std::cout << "Tree: ";
            tree.Display();
            std::cout << "\n";
            
        } else if (input == "6") {
            tree.DisplayTree();
        
        } else if (input == "0"){
            break;
        }else {
            std::cout << "\n!!! Wprowadzono niewlasciwe dane !!!\n\n";
        }
        ///////f
    }
return 0;
}
