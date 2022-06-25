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

    //Struktura naglowek
    struct naglowek
    {
    int Size;
    int Width;
    int Height;
    short Planes;
    short BitCount;
    int Compression;
    int izeImage;
    int XPelsPerMeter;
    int YPelsPerMeter;
    int CUsed;
    int CImportant;
    } zdjecie;

    //Struktura naglowek plik
    struct FileHeader
    {
    short fType;
    int fSize;
    short fReserved1;
    short fReserved2;
    int fOffBits;
    } plik;

int main(int arc, char * argv[]) {

    //Otwieranie pliku
    FILE* f = fopen(argv[1], "rb");
    if (f == nullptr){std::cout << "Brak pliku";}
    else{std::cout << "Plik otwarty";}


}
