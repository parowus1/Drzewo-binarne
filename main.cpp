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
            if(value[0] <= '9' && value[0] >='0'){
                //dodawanie elementow
            } else {
                std::cout<< "\n!!! That is not a number !!!\n\n";
            }
            
            } else if (input == "2") {
            std::cout << "Wprowadz element do usuniecia: ";
            std::cin >> value;
            if(value[0] <= '9' && value[0] >='0'){
                //usuwanie elementow
            } else {
                std::cout<< "\n!!! That is not a number !!!\n\n";
            }
        } else if (input == "3") {
           // czyszczenie drzewa
            std::cout << "Drzewo usuniete.\n";
        } else {
            break;
        }
        
    }
return 0;
}
