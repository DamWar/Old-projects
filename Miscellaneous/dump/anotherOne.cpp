#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(){
    string line;
    vector<int> liczby;
    fstream myFile;
    int j;
    int dlugosc = 2;
    int maxDlugosc = 0;
    int pierwsza = 0;
    int dzielnik;
    int tempDzielnik;
    int maxDzielnik;
    myFile.open("liczby.txt");
    if( myFile.is_open() ){
        while( getline( myFile, line ) ){
               liczby.push_back( atoi( line.c_str() ) );
        }
    }
    for(int i = 0; i < liczby.size(); i++){
        j = i;
        dzielnik = __gcd(liczby[j], liczby[j+1]);
        j+=2;
        while(dzielnik != 1){
            tempDzielnik = dzielnik;
            dzielnik = __gcd(dzielnik, liczby[j++]);
            dlugosc++;
        }
        if( maxDlugosc < dlugosc-1 ){
            maxDlugosc = dlugosc-1;
            pierwsza = liczby[i];
            maxDzielnik = tempDzielnik;
        }
        dzielnik = 0;
        dlugosc = 2;
    }
    cout << pierwsza << ", " << maxDlugosc << ", " << maxDzielnik;

    return 0;
}
