#include <iostream>
#include <cstdlib>
#include <ctime>
int main()
{
    int strzal;
    int liczba;
    do
    {
        if (strzal){
    std::cout << "Prosze sprobowac trafic w liczbe od 1 do 1000" << std::endl;
    std::cin >> strzal;
    srand( time( NULL ) );
    int liczba = (( std::rand() % 1000 ) + 1 );
    std::cout << "Wylosowanie: " << liczba << std::endl;
        }
    } while (liczba != strzal && strzal <= 1000 && strzal >= 1);
    return 0;
}
