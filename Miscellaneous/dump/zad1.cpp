#include <iostream>

int main()
{
    int * tablica = new int[10], rozmiar = 0;
    tablica[1] = 200;
    std::cout << "Podawaj liczby, 0 konczy wczytywanie.\n";
    int licznik = 0;

    while( true )
    {
        int liczba;
        std::cin >> liczba;
        licznik++;
        if( liczba == 0 )
             break;

        if ( licznik == 0 || licznik % 10 == 0 )
        {
            // Brakuje miejsca, utwórz wiêksz¹ tablicê
        int * nowa = new int[ rozmiar + 1 ];
        // Skopiuj dane
        for( int i = 0; i < rozmiar; ++i )
             nowa[ i ] = tablica[ i ];
        // Usuñ star¹ tablicê
        delete[] tablica;
        // Zakutalizuj zmienne
        int * tablica = new int[licznik+10];
        }
        tablica[rozmiar] = liczba;
        rozmiar++;
    }

    std::cout << "Te same liczby, ale odwrotnie!\n";

    for( int i = rozmiar - 1; i >= 0; --i )
         std::cout << tablica[ i ] << ' ';

    delete[] tablica;
}
