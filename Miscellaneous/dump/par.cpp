#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    bool brokeFree;
    bool zamiana = true;
    int ileRazy;
    int pierwszyDlugosc, drugiDlugosc, wiekszyDlugosc, mniejszyDlugosc;
    int iM, iW, kM, kW, porowPrawo, parzystosc, dlW, dlM;
    int wiekszy[100001];
    int mniejszy[100001];
    int jedno;
    unsigned long long int sumaW;
    unsigned long long int sumaM;
    unsigned long long int sumaL;
    unsigned long long int sumaP;
    unsigned long long int mniejszaSumaL;
    unsigned long long int mniejszaSumaP;
    unsigned long long int wiekszaSumaL;
    unsigned long long int wiekszaSumaP;
    unsigned long long int sumaStron;
    unsigned long long int sumaLewo;
    unsigned long long int sumaPrawo;
    scanf( "%d", &ileRazy );
    for( int i = 0; i < ileRazy; ++i ){
        jedno = 0;
        brokeFree = false;
        iM = 0;
        parzystosc = 0;
        sumaW = 0;
        sumaM = 0;
        sumaL = 0;
        sumaP = 0;
        sumaStron = 0;
        sumaLewo = 0;
        sumaPrawo = 0;
        scanf( "%d %d", &pierwszyDlugosc, &drugiDlugosc );
        if ( pierwszyDlugosc > drugiDlugosc ){
            wiekszyDlugosc = pierwszyDlugosc;
            mniejszyDlugosc = drugiDlugosc;
            for( int j = 0; j < wiekszyDlugosc; ++j ){
                scanf( "%d", &wiekszy[j] );
                sumaW += wiekszy[j];
                kW = j;
            }
            for( int l = 0; l < mniejszyDlugosc; ++l ){
                scanf( "%d", &mniejszy[l] );
                sumaM += mniejszy[l];
                kM = l;
            }
        }
        else{
            wiekszyDlugosc = drugiDlugosc;
            mniejszyDlugosc = pierwszyDlugosc;
            for( int l = 0; l < mniejszyDlugosc; ++l ){
                scanf( "%d", &mniejszy[l] );
                sumaM += mniejszy[l];
                kM = l;
            }
            for( int j = 0; j < wiekszyDlugosc; ++j ){
                scanf( "%d", &wiekszy[j] );
                sumaW += wiekszy[j];
                kW = j;
            }
        }



        if ( mniejszyDlugosc == 1 ){
            if ( (mniejszy[0]%2) != 0 ){
                while( jedno < wiekszyDlugosc ){
                    if( (wiekszy[jedno]%2) != 0 ){
                        cout << 1 << "\n";
                        goto poczatekPetli;
                    }
                    ++jedno;
                }
                cout << 0 << "\n";
                goto poczatekPetli;
            }
            else{
                while( jedno < wiekszyDlugosc ){
                    if( (wiekszy[jedno]%2) == 0 ){
                        cout << 1 << "\n";
                        goto poczatekPetli;
                    }
                    ++jedno;
                }
                cout << 0 << "\n";
                goto poczatekPetli;
            }
        }
        for( int modujemy = 0; modujemy < wiekszyDlugosc; ++modujemy ){
            wiekszy[modujemy] %= 2;
        }
        for( int modujemy = 0; modujemy < mniejszyDlugosc; ++modujemy ){
            mniejszy[modujemy] %= 2;
        }

        iW = wiekszyDlugosc - mniejszyDlugosc;
        kW -= iW;
        sumaW %= 2;
        sumaM %= 2;
        if( wiekszyDlugosc != mniejszyDlugosc ){
            if ( sumaW != sumaM )
                parzystosc = 1;
            for ( int lewo = 0; lewo < iW; ++lewo )
                sumaL += wiekszy[lewo];
            for ( int prawo = kW+iW; prawo > kW; --prawo )
                sumaP += wiekszy[prawo];
            if (    ( (sumaL%2) == parzystosc ) || ( (sumaP%2) == parzystosc )   ){
                cout << mniejszyDlugosc << "\n";
                brokeFree = true;
            }
            else{
                porowPrawo = kW+1;
                for ( int iPorow = 0; iPorow < iW; ++iPorow ){
                    if( (wiekszy[iPorow]%2) != (wiekszy[porowPrawo]%2) ){
                        cout << mniejszyDlugosc << "\n";//chyba mniejszyDlugosc
                        brokeFree = true;
                        break;
                    }
                    ++porowPrawo;
                }
                if ( !brokeFree ){
                    if (   ( ( ( (sumaL + wiekszy[kW+iW])%2 ) == parzystosc ) || ( ( (sumaP + wiekszy[0])%2 ) == parzystosc ) )    &&   ( mniejszy[0]%2 == 0 || mniejszy[mniejszyDlugosc-1]%2 == 0 )    ){//0 lub iW
                            cout << mniejszyDlugosc-1 << "\n";
                            brokeFree = true;
                    }
                    else if (   ( ( ( (sumaL + wiekszy[kW+iW])%2 ) != parzystosc ) || ( ( (sumaP + wiekszy[0])%2 ) != parzystosc ) )    &&    ( mniejszy[0]%2 != 0 || mniejszy[mniejszyDlugosc-1]%2 != 0 )  ){//0 lub iW
                            cout << mniejszyDlugosc-1 << "\n";
                            brokeFree = true;
                    }
                    else{
                        int koniec = kW+iW;
                        mniejszaSumaL = wiekszy[koniec];
                        wiekszaSumaL = sumaL - wiekszy[0];
                        mniejszaSumaP = wiekszy[0];
                        wiekszaSumaP = sumaP - wiekszy[koniec];
                        for ( int poczatek = 2; poczatek < iW; ++poczatek ){
                            if (   ( ( (wiekszaSumaL + mniejszaSumaL)%2 ) == parzystosc ) || ( ( (wiekszaSumaP + mniejszaSumaP)%2 ) == parzystosc )    ){
                                if ( mniejszy[0]%2 == 0 || mniejszy[mniejszyDlugosc-1]%2 == 0 ){
                                    cout << mniejszyDlugosc-1 << "\n";
                                    brokeFree = true;
                                    break;
                                }
                            }
                            else if (   ( ( (wiekszaSumaL + mniejszaSumaL)%2 ) != parzystosc ) || ( ( (wiekszaSumaP + mniejszaSumaP)%2 ) != parzystosc )    ){
                                if ( mniejszy[0]%2 != 0 || mniejszy[mniejszyDlugosc-1]%2 != 0 ){
                                    cout << mniejszyDlugosc-1 << "\n";
                                    brokeFree = true;
                                    break;
                                }
                            }

                            --koniec;
                            mniejszaSumaL += wiekszy[koniec];
                            wiekszaSumaL -= wiekszy[poczatek];
                            mniejszaSumaL += wiekszy[poczatek];
                            wiekszaSumaL -= wiekszy[koniec];
                        }
                        /*for ( int poczatek = 1; poczatek < iW; ++poczatek ){
                            if (   ( ( (sumaL-wiekszy[poczatek] + wiekszy[koniec])%2 ) == parzystosc ) || ( ( (sumaP-wiekszy[koniec] + wiekszy[poczatek])%2 ) == parzystosc )    ){
                                if ( mniejszy[0]%2 == 0 || mniejszy[mniejszyDlugosc-1]%2 == 0 ){
                                    cout << mniejszyDlugosc-1 << "\n";
                                    brokeFree = true;
                                }
                            }
                            else if (   ( ( (sumaL-wiekszy[poczatek] + wiekszy[koniec])%2 ) != parzystosc ) || ( ( (sumaP-wiekszy[koniec] + wiekszy[poczatek])%2 ) != parzystosc )    ){
                                if ( mniejszy[0]%2 == 0 || mniejszy[mniejszyDlugosc-1]%2 != 0 ){
                                    cout << mniejszyDlugosc-1 << "\n";
                                    brokeFree = true;
                                }
                            }
                            --koniec;
                        }*/
                    }
                }
                //czy ktos z wiekszych nie zmienia a mniejszy zmienia
                //wrong
                /*for ( int porowPrawo = kW+1; porowPrawo <= kW+iW; ++porowPrawo ){//verify
                    if ( wiekszy[porowPrawo] != wiekszy[0] ){
                        ++sumaStron;
                    }
                }
                if ( (sumaStron%2) == 1 ){
                    cout << wiekszyDlugosc-iW << "\n";
                    brokeFree = true;
                }
                else{
                    porowPrawo = wiekszyDlugosc-1;
                    for (int iPorow = 1 ; iPorow < iW-1; ++iPorow ){
                        if ( wiekszy[porowPrawo] != wiekszy[iPorow] ){
                            cout << wiekszyDlugosc-iW << "\n";
                            brokeFree = true;
                            break;
                        }
                        --porowPrawo;
                    }
                }*/

                if ( !brokeFree ){
                    /*for ( int obuStronnie = 0; obuStronnie < iW+1; ++obuStronnie ){
                        sumaLewo += wiekszy[obuStronnie];
                    }
                    for ( int obuStronnie = kW+iW; obuStronnie > kW-1; --obuStronnie ){
                        sumaPrawo += wiekszy[obuStronnie];
                    }
                    if (    ( mniejszy[1] != (sumaLewo%2) ) || ( mniejszy[1] != (sumaPrawo%2) )     ||    ( mniejszy[kM-1] != (sumaLewo%2) ) || ( mniejszy[kM-1] != (sumaPrawo%2) )  ){
                        cout << mniejszyDlugosc-1 << "\n";
                    }*/

                    while( iW != wiekszyDlugosc ){
                        if ( (wiekszy[iW]%2) != 0 ){
                            if ( mniejszy[iM] == 0 || mniejszy[kM] == 0 ){
                                cout << (mniejszyDlugosc-iM)-1 << "\n";
                                brokeFree = true;
                                break;
                            }
                        }
                        else{
                            if ( mniejszy[iM] != 0 || mniejszy[kM] != 0 ){
                                cout << (mniejszyDlugosc-iM)-1 << "\n";//
                                brokeFree = true;
                                break;
                            }
                        }
                        if ( (wiekszy[kW]%2) != 0 ){
                            if ( mniejszy[iM] == 0 || mniejszy[kM] == 0 ){
                                cout << (mniejszyDlugosc-iM)-1 << "\n";
                                brokeFree = true;
                                break;
                            }
                        }
                        else{
                            if ( mniejszy[iM] != 0 || mniejszy[kM] != 0 ){
                                cout << (mniejszyDlugosc-iM)-1 << "\n";
                                brokeFree = true;
                                break;
                            }
                        }
                        ++iM;
                        ++iW;
                        --kM;
                        --kW;
                    }
                }
            }
        }
        else{
            if ( sumaW != sumaM ){
                while( iW != wiekszyDlugosc ){
                        if ( (wiekszy[iW]%2) != 0 ){
                            if ( mniejszy[iM] == 0 || mniejszy[kM] == 0 ){
                                cout << (mniejszyDlugosc-iM)-1 << "\n";
                                brokeFree = true;
                                break;
                            }
                        }
                        else{
                            if ( mniejszy[iM] != 0 || mniejszy[kM] != 0 ){
                                cout << (mniejszyDlugosc-iM)-1 << "\n";//
                                brokeFree = true;
                                break;
                            }
                        }
                        if ( (wiekszy[kW]%2) != 0 ){
                            if ( mniejszy[iM] == 0 || mniejszy[kM] == 0 ){
                                cout << (mniejszyDlugosc-iM)-1 << "\n";
                                brokeFree = true;
                                break;
                            }
                        }
                        else{
                            if ( mniejszy[iM] != 0 || mniejszy[kM] != 0 ){
                                cout << (mniejszyDlugosc-iM)-1 << "\n";
                                brokeFree = true;
                                break;
                            }
                        }
                        ++iM;
                        ++iW;
                        --kM;
                        --kW;
                    }
            }
            else{
                cout << mniejszyDlugosc << "\n";
                brokeFree = true;
            }
        }
        if ( (wiekszyDlugosc-iW) < 0 ){
            cout << mniejszyDlugosc-iM << "\n";
            brokeFree = true;
        }
        else if ( (mniejszyDlugosc-iM) < 0 ){
            cout << wiekszyDlugosc-iW << "\n";
            brokeFree = true;
        }

        if ( brokeFree == false ){
            if ( (wiekszyDlugosc-iW) > (mniejszyDlugosc-iM) ){
                cout << wiekszyDlugosc-iW << "\n";
            }
            else{
                cout << mniejszyDlugosc-iM << "\n";
            }
        }

        poczatekPetli:
        if ( pierwszyDlugosc > drugiDlugosc ){
            for( int j = 0; j < pierwszyDlugosc; ++j ){
                wiekszy[j] = 0;
            }
            for( int l = 0; l < drugiDlugosc; ++l ){
                mniejszy[l] = 0;
            }
        }
        else{
            for( int j = 0; j < drugiDlugosc; ++j ){
                wiekszy[j] = 0;
            }
            for( int l = 0; l < pierwszyDlugosc; ++l ){
                mniejszy[l] = 0;
            }
        }

    }

    return 0;
}
