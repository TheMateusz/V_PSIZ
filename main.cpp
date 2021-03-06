#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <limits.h>

    //Struktura kolor?w
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
    int SizeImage;
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
    FILE* f = fopen(argv[], "rb");
    if (f == nullptr){std::cout << "Brak pliku\n\n";}
    else{std::cout << "Plik otwarty\n\n";}

    //Wyswietlanie informacji
    std::cout << "Informacje o pliku:\n";
    fread(&Plik.fType, sizeof(Plik.fType), 1, f);
    std::cout << "Typ: " << Plik.fType << "\n";
    fread(&Plik.fSize, sizeof(Plik.fSize), 1, f);
    std::cout << "Rozmiar: " << Plik.fSize << "\n";
    fread(&Plik.fReserved1, sizeof(Plik.fReserved1), 1, f);
    std::cout << "Rezerwacja 1: " << Plik.fReserved1 << "\n";
    fread(&Plik.fReserved2, sizeof(Plik.fReserved2), 1, f);
    std::cout << "Rezerwacja 2: " << Plik.fReserved2 << "\n";
    fread(&Plik.fOffBits, sizeof(Plik.fOffBits), 1, f);
    std::cout << "Pozycja danych: " << Plik.fOffBits << "\n";
    fseek(f, 14, SEEK_SET);
    fread(&zdjecie.Size, sizeof(zdjecie.Size), 1, f);
    std::cout << "Naglowek wielkosc: " << zdjecie.Size << "\n";
    fread(&zdjecie.Width, sizeof(zdjecie.Width), 1, f);
    std::cout << "Szerokosc: " << zdjecie.Width << "\n";
    fread(&zdjecie.Height, sizeof(zdjecie.Height), 1, f);
    std::cout << "Wysokosc: " << zdjecie.Height << "\n";
    fread(&zdjecie.Planes, sizeof(zdjecie.Planes), 1, f);
    std::cout << "Liczba platow: " << zdjecie.Planes << "\n";
    fread(&zdjecie.BitCount, sizeof(zdjecie.BitCount), 1, f);
    std::cout << "Bitow x piksel: " << zdjecie.BitCount << "\n";
    fread(&zdjecie.Compression, sizeof(zdjecie.Compression), 1, f);
    std::cout << "Kompresja: " << zdjecie.Compression << "\n";
    fread(&zdjecie.SizeImage, sizeof(zdjecie.SizeImage), 1, f);
    std::cout << "Rozmiar rys: " << zdjecie.SizeImage << "\n";
    fread(&zdjecie.XPelsPerMeter, sizeof(zdjecie.XPelsPerMeter), 1, f);
    std::cout << "Rozdzielczosc X: " << zdjecie.XPelsPerMeter << "\n";
    fread(&zdjecie.YPelsPerMeter, sizeof(zdjecie.YPelsPerMeter), 1, f);
    std::cout << "Rozdzielczosc Y: " << zdjecie.YPelsPerMeter << "\n";
    fread(&zdjecie.CUsed, sizeof(zdjecie.CUsed), 1, f);
    std::cout << "Liczba kolorow: " << zdjecie.CUsed << "\n";
    fread(&zdjecie.CImportant, sizeof(zdjecie.CImportant), 1, f);
    std::cout << "Kolory w palecie: " << zdjecie.CImportant << "\n";

    //Otwieranie pliku
    FILE* n = fopen("neg.bmp", "wb");
    if (n == nullptr){std::cout << "Brak pliku\n\n";}
    else{std::cout << "Plik otwarty\n\n";}

    //Wgrywanie do pliku
    fseek(n, 14, SEEK_SET);
    fwrite(&Plik.fType, sizeof(Plik.fType), 1, n);
    fwrite(&Plik.fSize, sizeof(Plik.fSize), 1, n);
    fwrite(&Plik.fReserved1, sizeof(Plik.fReserved1), 1, n);
    fwrite(&Plik.fReserved2, sizeof(Plik.fReserved2), 1, n);
    fwrite(&Plik.fOffBits, sizeof(Plik.fOffBits), 1, n);
    fseek(n, 14, SEEK_SET);
    fwrite(&zdjecie.Size, sizeof(zdjecie.Size), 1, n);
    fwrite(&zdjecie.Width, sizeof(zdjecie.Width), 1, n);
    fwrite(&zdjecie.Height, sizeof(zdjecie.Height), 1, n);
    fwrite(&zdjecie.Planes, sizeof(zdjecie.Planes), 1, n);
    fwrite(&zdjecie.BitCount, sizeof(zdjecie.BitCount), 1, n);
    fwrite(&zdjecie.Compression, sizeof(zdjecie.Compression), 1, n);
    fwrite(&zdjecie.SizeImage, sizeof(zdjecie.SizeImage), 1, n);
    fwrite(&zdjecie.XPelsPerMeter, sizeof(zdjecie.XPelsPerMeter), 1, n);
    fwrite(&zdjecie.YPelsPerMeter, sizeof(zdjecie.YPelsPerMeter), 1, n);
    fwrite(&zdjecie.CUsed, sizeof(zdjecie.CUsed), 1, n);
    fwrite(&zdjecie.CImportant, sizeof(zdjecie.CImportant), 1, n);
    fseek(n, sizeof(Plik.fOffBits), SEEK_SET);

    int bI;
    for (int i = Plik.fOffBits; i < Plik.fSize; i++)
    {
        fseek(f, i, SEEK_SET);
        fseek(n, i, SEEK_SET);
        fread(&bI, 3, 1, f);
        bI = INT_MAX - bI;
        fwrite(&bI, 3, 1, n);
    }

    fclose(f);
    fclose(n);
}
