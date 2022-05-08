#include <iostream>
using namespace std;

int main()
{
    int dwa = 2;
    int cztery = 4;
    cout << "Mozesz wykonac jedno z czterech dzialan, +(1), -(2), *(3) i /(4) na liczbach 2 i 4" << endl;
    int znak;
    cin >> znak;
    switch(znak)
    {
    case 1:
        cout << 2 + 4;
        break;
    case 2:
        cout << 2 - 4;
        break;
    case 3:
        cout << 2 * 4;
        break;
    case 4:
        cout << 2 / 4;
        break;
    default:
        cout << "Nieprawidlowy znak";
        break;
    }
    return 0;
}
