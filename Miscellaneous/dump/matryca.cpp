#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>

using namespace std;

int main(){
    int i, j;
    int numRows = 87;
    int halfish = (numRows/2)-10;
    int inRow = 130;
    short int ifTenth = 0;
    string output = "";
    system("mode 650");
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    while(true){
        if( ifTenth != 10 ){
            i++;
        }else{
            srand(time(NULL));
            i = 0;
        }


        for( i = 0; i < halfish; i++){
            for( j = 0; j < inRow; j++ ){
                output += char((rand()%10)+48);
                output += " ";
            }
            output += "\n";
        }
        cout << output;
        output = "";
        SetConsoleTextAttribute(hConsole, 10);
        for( i = 0; i < 20; i++){
            for( j = 0; j < inRow; j++ ){
                output += char((rand()%10)+48);
                output += " ";
            }
            output += "\n";
        }
        cout << output;
        output = "";
        SetConsoleTextAttribute(hConsole, 2);
        for( i = 0; i < halfish; i++){
            for( j = 0; j < inRow; j++ ){
                output += char((rand()%10)+48);
                output += " ";
            }
            output += "\n";
        }
        cout << output;
        output = "";
        Sleep(100);
    }
    system("pause");
    return 0;
}
