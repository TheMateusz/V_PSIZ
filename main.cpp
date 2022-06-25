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
    } kolor;

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
    struct NaglowekPlik
    {
    short fType;
    int fSize;
    short fReserved1;
    short fReserved2;
    int fOffBits;
    } Plik;

int main(int arc, char * argv[]) {

    //Otwieranie pliku
    FILE* f = fopen("zdjecie.bmp", "rb");
    if (f == nullptr){std::cout << "Brak pliku\n\n";}
    else{std::cout << "Plik otwarty\n\n";}

    std::cout << "Informacje o pliku:\n";

    fread(&Plik.fType, sizeof(Plik.fType), 1, f);
    std::cout << "Typ: " << Plik.fType << "\n";



}
