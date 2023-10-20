#include <iostream>
#include <string>


int main() {
    DrzewoBinarne tree;
    std::string input;
    bool running = true;

    while (running) {
        std::cout << "Menu Binarnego Drzewa:\n";
        std::cout << "1. Dodaj element\n";
        std::cout << "2. Usuń element\n";
        std::cout << "3. Usuń całe drzewo\n";
        std::cout << "4. Szukaj elementu\n";
        std::cout << "5. Wyświetl drzewo\n";
        std::cout << "6. Zapisz drzewo do pliku\n";
        std::cout << "7. Wczytaj drzewo z pliku\n";
        std::cout << "8. Wczytaj plik tekstowy z cyfer\n";
        std::cout << "9. Wyjście\n";
        std::cout << "Wpisz swój wybór: ";
        std::cin >> input;

    
return 0;
}
