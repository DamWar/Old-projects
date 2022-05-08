#include <iostream>
#include <bitset>
using namespace std;

int main(){
    long long n = 300;//978945678412345678;
    long long z = 2;
    while (z * z <= n) {
        if (n % z == 0) {
            cout << z << endl;
            n /= z;
        } else {
            z++;
        }
    }
    if (n > 1) {
        cout << n << endl;
    }
    //cout << bitset<3>(978945678412345678);
}
