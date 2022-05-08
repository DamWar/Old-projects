#include <iostream>
#include <fstream>

void sortuj(int* begin, int* end)
{
    int *beginning = begin;
    int *check = begin;
    int *pom = begin;
    while ( check != end )
    {
        while ( begin != end )
        {
            if ( *check < *begin )
            {
                *pom = *check;
                *check = *begin;
                *begin = *pom;
                //std::cout << "wykonano" << std::endl;
            }
            ++begin;
        }
        begin=beginning;
        ++check;
    }
}

void wypisz( int * begin, int size )
{
    while( size > 0 )
    {
        std::cout << * begin << ' ';
        ++begin;
        --size;
    }
}

int main()
{
    int tab[ 10 ] = { 0, 9, 1, 3, 8, 2, 6, 7, 5, 4 };
    sortuj( tab, tab + 10 );
    wypisz( tab, 10 );
    return 0;
}
