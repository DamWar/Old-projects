#include <iostream>
#define WINVER 0x0500
#include <windows.h>
#include <cstdlib>
#include <ctime>
int main()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    srand( time( NULL ) );
    int czassnu = 0;
    bool z = false;

    while(1)
    {
        czassnu=( std::rand() % 500 ) + 1000;
        Sleep(czassnu);
        ip.ki.wVk = 0x7A;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(czassnu);
        czassnu=( std::rand() % 200 ) + 1000;
        ip.ki.wVk = 0x70;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(czassnu-500);
        ip.ki.wVk = 0xA3;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(czassnu-800);
        if (!z)
        {
            ip.ki.wVk = 0x27;
            ip.ki.dwFlags = 0;
            SendInput(1, &ip, sizeof(INPUT));
            ip.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));
        }
        else
        {
            ip.ki.wVk = 0x25;
            ip.ki.dwFlags = 0;
            SendInput(1, &ip, sizeof(INPUT));
            ip.ki.dwFlags = KEYEVENTF_KEYUP;
            SendInput(1, &ip, sizeof(INPUT));
        }
        z = !z;
        ip.ki.wVk = 0xA3;
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
    }
    return 0;
}
