#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    vector<char>ciag1;
    vector<char>ciag2;
    char k;
    do{
        scanf("%c", &k);
        ciag1.push_back(k);
    }while( k != '\n' );
    do{
        scanf("%c", &k);
        ciag2.push_back(k);
    }while( k != '\n' );

    vector<char>podciag1;
    vector<char>podciag2;
    vector<char>::const_iterator i = ciag1.begin();
    vector<char>::const_iterator j = ciag2.begin();
    vector<char>::const_iterator temp = j;
    vector<char>::const_iterator x;
    short int howMany = 0;
    short int licznik = 0;
    short int a[4];
    bool rozne = false;
    a[0] = *i;
    while ( howMany != 4 && i != ciag1.end() ){
        do{
            if( *i != a[licznik] ){
                ++howMany;
                a[licznik] = *i;
            }
            ++licznik;
        }while( licznik < howMany && licznik < 4 );
        howMany -= (licznik-1);
        ++i;
        licznik = 0;
    }
    i = ciag1.begin();
    short int zakoncz = 0;
    while ( zakoncz != howMany ){
        while ( j != ciag2.end() ){
            if( *i == *j ){
                podciag1.push_back(*i);
                ++i;
                temp = ++j;
            }
            else
                ++j;
        }
        j = temp;
        ++i;
        ++zakoncz;
    }
    howMany = 0;
    zakoncz = 0;
    temp = i;
    i = ciag1.begin();
    j = ciag2.begin();

    a[0] = *j;
    while ( howMany != 4 && j != ciag1.end() ){
        do{
            if( *j != a[licznik] ){
                ++howMany;
                a[licznik] = *j;
            }
            ++licznik;
        }while( licznik < howMany && licznik < 4 );
        howMany -= (licznik-1);
        ++j;
        licznik = 0;
    }
    j = ciag2.begin();
    while ( zakoncz != howMany ){
        while ( i != ciag1.end() ){
            if( *j == *i ){
                podciag2.push_back(*j);
                ++j;
                temp = ++i;
            }
            else
                ++i;
        }
        i = temp;
        ++j;
        ++zakoncz;
    }

    i = podciag1.begin();
    j = podciag2.begin();
    if ( podciag1.size() > podciag2.size() ){
        while( true ){
            if ( *i != *j ){
                if ( rozne == true ){
                    i = podciag1.begin();
                    while( i != podciag1.end() ){
                        cout << *i;
                        ++i;
                    }
                    break;
                }
                else
                    rozne = true;
            }
            if( j == podciag2.end() ){
                j = podciag2.begin();
                while( j != podciag2.end() ){
                cout << *j;
                ++j;
                }
                break;
            }
            if ( *i == *j )
                ++j;
            ++i;
        }
    }
    else if( podciag1.size() < podciag2.size() ){
        while( true ){
            if ( *i != *j ){
                if ( rozne == true ){
                    j = podciag2.begin();
                    while( j != podciag2.end() ){
                        cout << *j;
                        ++j;
                    }
                    break;
                }
                else
                    rozne = true;
            }
            if( i == podciag1.end() ){
                i = podciag1.begin();
                while( i != podciag1.end() ){
                cout << *i;
                ++i;
                }
                break;
            }
            if ( *i == *j )
                ++i;
            ++j;
        }
    }

    return 0;
}
