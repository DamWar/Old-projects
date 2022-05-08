#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int iloscPodciagow = 2997;
    long long int pomocnicza;
    short int ktoraPotega = 0;
    int porownanie;
    int dodawanieJedenZnak;
    int polowaCiagu;

    char znaki[62] = {48,49,50,51,52,53,54,55,56,57,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122};
    if ( iloscPodciagow > 1 && iloscPodciagow < 1002 ){
        char maly[iloscPodciagow-1];//sprawdzic zachowanie przy wiekszej ilosci przykladow
        for( int i = 0; i < iloscPodciagow-1; ++i ){
           cout << 'a';
        }
        cout << "\n";
        //continue;
    }
    if ( (iloscPodciagow & (iloscPodciagow - 1)) == 0 ){
        ktoraPotega = 0;
        do{
            iloscPodciagow/=2;
            ++ktoraPotega;
        }while( iloscPodciagow != 1 );
        for( int i = 0; i < ktoraPotega; ++i ){
            cout << znaki[i];
        }
        cout << "\n";
        //continue;
    }
    //sprawdzanie pelnych ciagow z pojedynczymi literami
    if ( iloscPodciagow <= 251500 ){
        for( int i = 11; i <= 1000; ++i ){
            porownanie = i;//zbedne
            dodawanieJedenZnak = porownanie;
            if ( (polowaCiagu%2) != 0 ){
                polowaCiagu = i/2 + 1;
            }
            polowaCiagu = i/2;
            for( int j = 0; j < polowaCiagu; ++j ){
                porownanie += dodawanieJedenZnak;
                if ( iloscPodciagow == porownanie ){
                    char maly[i];
                    for( int k = 0; k < i; ++k ){
                        if ( k != j )
                            cout << 'a';
                        else
                            cout << 'A';
                    }
                    cout << "\n";
                    goto Poczatek;
                }
                dodawanieJedenZnak -= 2;
            }
        }
    }
    Poczatek:
    //pomiedzy ktorymi potegami
    pomocnicza = iloscPodciagow;
    while(pomocnicza != 0){
        ++ktoraPotega;
        pomocnicza >>= 1;
    }
    cout << ktoraPotega;

    /*char a = 0;
    for( int i = 0; i < 256; ++i ){
        cout << "\n" << i << " " << a++;
        for( int j = 0; j < 62; ++j ){
            if ( znaki[j] == i ){
                cout << " " << znaki[j];
            }
        }
    }*/
    return 0;
}
