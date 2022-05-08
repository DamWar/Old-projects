#include <iostream>
#include <string>
#include <fstream>

/*
int main()
{
std::string imie[ 2 ];
std::string nazwisko[ 2 ];
int wiek[ 2 ];

for( int i = 0; i < 2; i++ )
{
    std::getline(std::cin, imie[i]);
    std::getline(std::cin, nazwisko[i]);
    std::cin >> wiek[i];
    if (wiek[i]==0)
    {
        std::cout << "Wprowadzono bledna wartosc! Wracaj do pocz¹tku swoich danych!" << std::endl;
        i--;
    }
    std::cin.clear();
    std::cin.sync();
}

for( int i = 0; i < 2; i++ )
{
    std::cout << "Imie: " << imie[i] << std::endl;
    std::cout << "Nazwisko: " << nazwisko[i] << std::endl;
    std::cout << "Wiek: " << wiek[i] << std::endl;
}

return 0;
}
*/
/*
bool szukaj( std::string & tekst, std::string wyraz1, std::string wyraz2 )
{
    size_t znalezionaPozycja = tekst.find( wyraz1 );
    size_t znalezionaPozycja2 = tekst.find( wyraz2 );
    if( znalezionaPozycja == std::string::npos || znalezionaPozycja2 == std::string::npos )
        return false;
    else
        return true;
}

void wypiszWynik( bool czyZnaleziono )
{
    if( czyZnaleziono )
         std::cout << "Znaleziono" << std::endl;
    else
         std::cout << "Nie znaleziono" << std::endl;

}

int main()
{
    std::string napis = "Zadanie domowe z kursu C++ (http://cpp0x.pl) - najlepszy kurs C++ w Internecie!";
    wypiszWynik( szukaj( napis, "ada", "kurs" ) );
    wypiszWynik( szukaj( napis, "ada", "taki" ) );
    wypiszWynik( szukaj( napis, "C++", "cpp0x" ) );
    wypiszWynik( szukaj( napis, "C#", "cpp0x" ) );
    return 0;
}
*/
/*
int main()
{
    for (int a=1; a<=3; a++)
    {
        for (int b=1; b<=3; b++)
        {
            for (int c=1; c<=3; c++)
            {
                for (int d=1; d<=3; d++)
                {
                    for (int e=1; e<=3; e++)
                    {
                        std::cout << a;
                        std::cout << b;
                        std::cout << c;
                        std::cout << d;
                        std::cout << e;
                        std::cout << std::endl;
                    }
                }
            }
        }
    }
    return 0;
}
*/
/*
bool wyswietlZawartoscPliku( std::string tekscikzkursucpp )
{
    std::string szukanaFraza;
    std::cin >> szukanaFraza;
    std::ifstream plik;
    plik.open( "D:/program files/tekscikzkursucpp.txt" );
    if( !plik.good() )
         return false;

    std::string wiersz;
    while( std::getline( plik, wiersz ) )
    {
        size_t znalezionaPozycja = wiersz.find( szukanaFraza );
            if( znalezionaPozycja == std::string::npos )
            {
                continue;
            }
         std::cout << wiersz << std::endl;
    }

    plik.close();
    return true;
}

int main()
{
    if( !wyswietlZawartoscPliku( "D:/program files/tekscikzkursucpp.txt" ) )
         std::cout << "Nie udalo sie otworzyc pliku o podanej nazwie." << std::endl;

    return 0;
}
*/
/*
int main()
{
    std::ifstream plik;
    plik.open( "D:/program files/tekscikzkursucpp.txt" );
    int a=0;
    int suma=0;
    while( !plik.eof() )
    {
        plik >> a;
        if( plik.fail() )
        {
            plik.clear();
            plik.get();
            continue;
        }
        std::cout << a << " ";
        suma+=a;
    }
    std::cout << std::endl << "Suma liczb wynosi: " << suma;
}
*/
bool czyNapotkanoZnakNowegoWiersza( std::ifstream & plik )
{
    char cZnak;
    for( ;; ) //nieskończona pętla
    {
        plik.clear();
        cZnak = plik.peek(); //sprawdzamy jaki kolejny znak zostanie zwrócony przez operację odczytu
        if( plik.fail() || plik.bad() )
             return false; //wystąpił błąd odczytu danych

        if( !isspace( cZnak ) )
             return false; //pobrany znak nie jest białym znakiem

        plik.get( cZnak ); //odczytujemy biały znak z pliku
        if( plik.fail() || plik.bad() )
             return false; //wystąpił błąd odczytu danych

        if( cZnak == '\n' )
             return true;

    } //for
}
int main()
{
    std::ifstream plik;
    plik.open( "D:/program files/tekscikzkursucpp.txt" );
    int a=0;
    int suma=0;
    int wiersz=0;
    char b;
    //int wykonania=0;
    while( !plik.eof() )
    {
        wiersz++;
        while (!czyNapotkanoZnakNowegoWiersza(plik))
        {
            plik.clear();
            plik >> a;
            //wykonania++;
            suma+=a;
            if( plik.fail() )
            {
                std::cout << "Bledne dane w wierszu nr: " << wiersz << std::endl;
                suma=0;
                break;
            }
        }
        if( plik.fail() )
        {
            std::cout << a << std::endl;
            std::cout << " kontynuowano" << std::endl;
            continue;
        }
        /*plik.close();
        plik.open( "D:/program files/tekscikzkursucpp.txt" );
        for(int i=0; i<wiersz; i++)
        {
            while (!czyNapotkanoZnakNowegoWiersza(plik))
            {
                plik.clear();
                plik >> a;
                wykonania++;
                if( plik.fail() )
                {
                    break;
                }
            }
        }
        for(int i=0; i<wykonania; i++)
        {
            plik >> a;
            suma+=a;
        }*/
        std::cout << suma << std::endl;
        suma=0;
    }
    std::cout << std::endl << suma;
    return 0;
}
