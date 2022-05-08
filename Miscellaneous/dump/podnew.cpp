#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    long long int n;//ilosc podciagow
    long long int czynnikPierwszy;
    char znaki[62] = {48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122};
    int ktoryCzynnik;
    short int suma;
    long long int czynniki[60];//przechowywanie czynnikow
    long long int pomocnicza;
    short int ktoraPotega;
    short int prawiePotega[60] = {0};
    bool czyCzyscic[60] = {false};
    short int indeksZnaku, pierwszyZnak;
    int q;//tyle zestawow
    scanf( "%d", &q );
    for( int zestaw = 0; zestaw < q; ++zestaw ){
        scanf( "%lld", &n );
        czynnikPierwszy = 2;
        ktoryCzynnik = 0;
        suma = 0;
        while( czynnikPierwszy * czynnikPierwszy <= n ){
            if ( n % czynnikPierwszy == 0 ){
                czynniki[ktoryCzynnik] = czynnikPierwszy;
                ++ktoryCzynnik;
                n /= czynnikPierwszy;
                suma += czynnikPierwszy-1;
            }
            else{
                ++czynnikPierwszy;
            }
        }
        if ( n > 1 ){
            czynniki[ktoryCzynnik] = n;
            ++ktoryCzynnik;
            suma += n-1;
        }
        if ( suma > 1000 ){
            for( int i = 0; i < ktoryCzynnik; ++i ){
                if ( (czynniki[i] & czynniki[i]+1) == 0 )
                ktoraPotega = 0;
                pomocnicza = czynniki[i];
                while(pomocnicza != 0){
                    ++ktoraPotega;
                    pomocnicza >>= 1;
                }
                suma -= czynniki[i];
                suma += ktoraPotega;
                prawiePotega[i] = ktoraPotega;
                czyCzyscic[i] = true;
            }
            if ( suma > 1000 ){
                for( int i = 0; i < ktoryCzynnik; ++i ){
                    if ( czyCzyscic[i] ){
                        prawiePotega[i] = 0;
                    }
                }
                cout << "!\n";
                continue;
            }
            else{
                indeksZnaku = 0;
                for( int i = 0; i < ktoryCzynnik; ++i ){
                    if ( prawiePotega[i] == 0 ){
                        for( int j = 1; j < czynniki[i]; j++ ){
                            cout << znaki[indeksZnaku++];
                        }
                    }
                    else{
                        pierwszyZnak = indeksZnaku;
                        for( int j = 1; j < prawiePotega[i]; j++ ){// wciag z = 1, poniewaz mimo -- z faktu wypisywania prawie potegi dwojki, ostatni znak jest tym samym, co pierwszy
                            cout << znaki[indeksZnaku++];
                        }
                        cout << znaki[pierwszyZnak];
                    }
                }
                for( int i = 0; i < ktoryCzynnik; ++i ){
                    if ( czyCzyscic[i] ){
                        prawiePotega[i] = 0;
                    }
                }
                cout << "\n";
                continue;
            }

        }
        for( int i = 0; i < ktoryCzynnik; ++i ){
            for( int j = 1; j < czynniki[i]; j++ ){
                cout << znaki[i];
            }
        }
        cout << "\n";

    }

    return 0;
}
