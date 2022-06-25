#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <limits.h>

    //Struktura kolorów
    struct kolor
    {
    char R;
    char G;
    char B;
    }

int main(int arc, char * argv[]) {

    //Otwieranie pliku
    FILE* f = fopen(argv[1], "rb");
    if (f == nullptr){std::cout << "Brak pliku";}
    else{std::cout << "Plik otwarty";}


}
