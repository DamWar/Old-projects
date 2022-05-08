#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdlib.h>
#include <string>

using namespace std;

int main(){
    string line;
    int poczatek;
    int liczba;
    int cyfra;
    int silnia = 1;
    int silnie = 0;
    fstream myFile;
    myFile.open("liczby.txt");
    if( myFile.is_open() ){
        while( getline( myFile, line ) ){
            liczba = atoi(line.c_str());
            poczatek = liczba;
            //cout << liczba << '\n';
            while( liczba / 10 != 0 ){
                cyfra = liczba % 10;
                //cout << cyfra << "\n";
                for( int i = cyfra; i > 1; i-- ){
                    silnia *= i;
                    //cout << i << " " << silnia << "\n";
                }
                silnie += silnia;
                silnia = 1;
                liczba = liczba/10;
                //cout << liczba << "\n";
            }
            cyfra = liczba % 10;
            for( int i = cyfra; i > 1; i-- ){
                silnia *= i;
                //cout << i << " " << silnia << "\n";
            }
            silnie += silnia;
            silnia = 1;
            //cout << silnie;
            //cin >> liczba;
            if( silnie == poczatek ){
                cout << poczatek << ' ';;
            }
            //cout << silnie << ' ';
            silnie = 0;
            //cin >> liczba;
        }
    }
    return 0;
}
