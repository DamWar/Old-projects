#include <iostream>
#include <math.h>

using namespace std;

int main(){
    char example = 129;
    int n = 6; //ilosc bajtow
    int bity = 4;
    int przedzialy = 8/bity;
    int znak = 0;
    int control = 8;
    //for( int i = 0; i < n; i++ ){
        for( int j = 0; j < przedzialy; j++ ){
            for( int k = control; k <= bity+control-1; k++ ){
                znak += pow( ((example & ( 1 << k )) >> k), k-1);
            }
            control += bity;
            cout << znak << endl;
        }
    //}


    return 0;
}
/*3.2
string s = "ASDFSGFDSGDFAHSDGSFDH";
    char d[100]; //bcs distinct
    int r = 0;
    bool rep = false;
    for( int z = 0; z < 100; z++ )
        d[z] = 0;
    for( int i = 0; i < s.length(); i++ ){
        for( int j = 0; j < r; j++ ){
            if( s[i] == d[j] ){
                rep = true;
                break;
            }
        }
        if( !rep ){
            d[r] = s[i];
            r++;
        }else{
            rep = false;
        }
    }
    cout << r;
*/
