#include <iostream>
#include <string>


int main() {
    //DrzewoBinarne tree;
    std::string input;
    bool running = true;

    while (running) {
        std::cout << "Menu Binarnego Drzewa:\n";
        std::cout << "1. Dodaj element\n";
        std::cout << "2. Usun element\n";
        std::cout << "3. Usun cale drzewo\n";
        std::cout << "4. Szukaj elementu\n";
        std::cout << "5. Wyswietl drzewo\n";
        std::cout << "6. Narysuj drzewo\n";
        std::cout << "7. Zapisz drzewo do pliku\n";
        std::cout << "8. Wczytaj drzewo z pliku\n";
        std::cout << "9. Wczytaj plik tekstowy z cyfer\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wpisz swoj wybor: ";
        std::cin >> input;

        int value;

        if (input == "1") {
            std::cout << "Wprowadz element do dodania: ";
            std::cin >> value;
            //tree.Insert(value);
            } else if (input == "2") {
            std::cout << "Wprowadz element do usuniecia: ";
            std::cin >> value;
            //tree.Remove(value);
        } else if (input == "3") {
           // tree.Clear();
            std::cout << "Drzewo usuniete.\n";
        } else {
            break;
        }
        
    }
return 0;
}
