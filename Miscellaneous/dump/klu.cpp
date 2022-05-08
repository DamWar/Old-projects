#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int n, m;
    scanf( "%d %d", &n, &m );
    vector<int> klubowicze(m);
    int maksymalna = (1 << n) - 1;
    int minimalna = 0;
    int obecnaMax = 0;
    int obecnaMin = maksymalna;
    int znaleziono[4] = {0, -1, -1, -1};
    int poczatek[3] = {0, -1, -1};//0 niepotrzebne, bardziej przejrzyste (chyba)
    short int ktoryZnalazlo = 0;

    for( int i = 0; i < m; ++i ){//przejscie przez tablice
        scanf( "%d", &klubowicze[i] );
        obecnaMax |= klubowicze[i];
        obecnaMin &= klubowicze[i];
        if (    ( obecnaMax == maksymalna ) && ( obecnaMin == 0 )    ){
            ++znaleziono[0];
            ++ktoryZnalazlo;
            obecnaMax = 0;
            obecnaMin = maksymalna;
            znaleziono[ktoryZnalazlo] = i; //LOW PRIORITY, niepotrzebny ostatni przebieg, mala strata a problematyczny kod
            if ( znaleziono[0] == 3 ){
                double polowaM = m/2;
                --polowaM;
                polowaM = pow(polowaM, 2);
                cout <<fixed<<(long long int)polowaM << " max";//( (m/2) - 1 ) * ( (m/2) - 1 );//tutaj wzor na maksymalna ilosc
                return 0;
            }
        }
    }

    if ( znaleziono[0] == 0 ){
        maksymalna = obecnaMax;
        minimalna = obecnaMin;

        obecnaMax = minimalna;
        obecnaMin = maksymalna;

        for( int i = 0; i < m; ++i ){//przejscie przez tablice
            obecnaMax |= klubowicze[i];
            obecnaMin &= klubowicze[i];
            if (    ( obecnaMax == maksymalna ) && ( obecnaMin == minimalna )    ){
                ++znaleziono[0];
                ++ktoryZnalazlo;
                obecnaMax = minimalna;
                obecnaMin = maksymalna;
                znaleziono[ktoryZnalazlo] = i; //LOW PRIORITY, niepotrzebny ostatni przebieg, mala strata a problematyczny kod
                if ( znaleziono[0] == 3 ){
                    double polowaM = m/2;
                    --polowaM;
                    polowaM = pow(polowaM, 2);
                    cout <<fixed<<(long long int)polowaM;//tutaj wzor na maksymalna ilosc
                    return 0;
                }
            }
        }
    }
    int tempMax = obecnaMax;
    int tempMin = obecnaMin;
    if ( znaleziono[0] == 1 ){
        // sprawdzenie przesuwania a potem dodanie poczatku do pozostalej czesci
        obecnaMax = minimalna;
        obecnaMin = maksymalna;
        for( int i = znaleziono[1]; i >= 0; --i ){//niepotrzebny warunek
            obecnaMax |= klubowicze[i];
            obecnaMin &= klubowicze[i];
            if (    ( obecnaMax == maksymalna ) && ( obecnaMin == minimalna )    ){
                poczatek[1] = i;
                break;
            }
        }
        for( int i = 0; i < poczatek[1]; ++i ){
            tempMax |= klubowicze[i];
            tempMin &= klubowicze[i];
            if (    ( tempMax == maksymalna ) && ( tempMin == minimalna )    ){
                //tak jak w przypadku znalezienia 2
                obecnaMax = minimalna;
                obecnaMin = maksymalna;
                for( int i = 0; i < poczatek[1]; ++i ){
                    obecnaMax |= klubowicze[i];
                    obecnaMin &= klubowicze[i];
                }
                for( int i = m-1; i >= 0; --i ){//niepotrzebny warunek
                    obecnaMax |= klubowicze[i];
                    obecnaMin &= klubowicze[i];
                    if (    ( obecnaMax == maksymalna ) && ( obecnaMin == minimalna )    ){
                        m = m - (   ( poczatek[1] + (m - i) ) + ( znaleziono[1] - poczatek[1] ) + 1 );//+1 dlatego, ze ta roznica daje liczbe o 1 mniejsza niz dl ciagu
                        double polowaM = m/2;
                        --polowaM;
                        polowaM = pow(polowaM, 2);
                        cout <<fixed<<(long long int)polowaM << "tutaj";//tutaj wzor na maksymalna ilosc
                        return 0;
                    }
                }
            }
        }
        cout << 0;
    }
    if ( znaleziono[0] == 2 ){
        obecnaMax = minimalna;
        obecnaMin = maksymalna;
        for( int i = znaleziono[1]; i >= 0; --i ){//niepotrzebny warunek
            obecnaMax |= klubowicze[i];
            obecnaMin &= klubowicze[i];
            if (    ( obecnaMax == maksymalna ) && ( obecnaMin == minimalna )    ){
                poczatek[1] = i;
                break;
            }
        }
        for( int i = 0; i < poczatek[1]; ++i ){
            tempMax |= klubowicze[i];
            tempMin &= klubowicze[i];
            if (    ( tempMax == maksymalna ) && ( tempMin == minimalna )    ){
                double polowaM = m/2;
                --polowaM;
                polowaM = pow(polowaM, 2);
                cout <<fixed<<(long long int)polowaM;//tutaj wzor na maksymalna ilosc
                return 0;
            }
        }
        obecnaMax = minimalna;
        obecnaMin = maksymalna;
        for( int i = znaleziono[2]; i > znaleziono[1]; --i ){//niepotrzebny warunek
            obecnaMax |= klubowicze[i];
            obecnaMin &= klubowicze[i];
            if (    ( obecnaMax == maksymalna ) && ( obecnaMin == minimalna )    ){
                poczatek[2] = i;
                break;
            }
        }
        m = m - (   ( znaleziono[2] - poczatek[2] ) + ( znaleziono[1] - poczatek[1] ) + 2   );//+2 dlatego, ze te roznica daja liczbe o 1 mniejsza niz dl ciagu
        double polowaM = m/2;
        --polowaM;
        polowaM = pow(polowaM, 2);
        cout <<fixed<<(long long int)polowaM;//tutaj wzor na maksymalna ilosc
        return 0;
    }


    return 0;
}
