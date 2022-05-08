#define WINVER 0x0500
#include <Windows.h>
#include <iostream>

class MoveMouse{
    int X = 1680;
    int Y = 1050;
    int fullRotation = X * 1.43;
    int halfRotation = fullRotation / 2;
    int rightAngle = halfRotation / 2;
    int holdX = X / 2;
    int holdY = Y / 2;
    int stepRight = holdX + 1;
    int stepLeft = holdX - 1;
    int stepUp = holdY - 1;
    int stepDown = holdY + 1;
    //
public:
    void clickIt(int seconds){
        int secondsx = seconds * 1000;
        INPUT HoldIt;
        INPUT ReleaseIt;
        HoldIt.type = INPUT_MOUSE;
        HoldIt.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
        ReleaseIt.type = INPUT_MOUSE;
        ReleaseIt.mi.dwFlags = MOUSEEVENTF_LEFTUP;
        SendInput(1, &HoldIt, sizeof(INPUT));
        Sleep(secondsx);
        SendInput(1, &ReleaseIt, sizeof(INPUT));
    }
    void movearrow(int seconds, int arrow){
        int secondsx = seconds * 1000;
        INPUT ip;
        ip.type = INPUT_KEYBOARD;
        ip.ki.wVk = arrow;
        ip.ki.dwFlags = 0;
        SendInput(1, &ip, sizeof(INPUT));
        Sleep(secondsx);
        ip.ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &ip, sizeof(INPUT));
    }
    //
    void lookDown(){
        for(int i = 0; i < halfRotation; i++){
            Sleep(20);
            SetCursorPos( holdX, stepDown );
        }
    }
    void lookUp(){
        for(int i = 0; i < halfRotation; i++){
            Sleep(20);
            SetCursorPos( holdX, stepUp );
        }
    }
    void lookBack(){
        for(int i = 0; i < halfRotation; i++){
            Sleep(20);
            SetCursorPos( stepRight, holdY );
        }
    }
    void turnRight(){
        for(int i = 0; i < rightAngle; i++){
            Sleep(20);
            SetCursorPos( stepRight, holdY );
        }
    }
    void turnLeft(){
        for(int i = 0; i < rightAngle; i++){
            Sleep(20);
            SetCursorPos( stepLeft, holdY );
        }
    }
    void centerY(){
        lookDown();
        for(int i = 0; i < rightAngle; i++){
            Sleep(20);
            SetCursorPos( holdX, stepUp );
        }
    }
    void mineLowerPart(){
        for(int i = 0; i < (fullRotation / 36); i++){
            Sleep(20);
            SetCursorPos( holdX, stepDown );
        }
        clickIt(3);
        for(int i = 0; i < (fullRotation / 24); i++){
            Sleep(20);
            SetCursorPos( holdX, stepDown );
        }
        clickIt(2);
    }
    void lookUpperPart(){
        for(int i = 0; i < ( (fullRotation / 36) + (fullRotation / 24) ); i++){
            Sleep(20);
            SetCursorPos( holdX, stepUp );
        }
    }
}moveMouse;

int main()
{
    int W = 0x26;
    int A = 0x25;
    int S = 0x28;
    int D = 0x27;
    Sleep(3000);

    moveMouse.centerY();

    for ( int j = 0; j < 29; j++ ){
        for( int j = 0; j < 6; j++ ){
            moveMouse.clickIt(5);
            moveMouse.mineLowerPart();
            moveMouse.movearrow(3, W);
            moveMouse.lookUpperPart();
        }
        moveMouse.lookBack();
        moveMouse.movearrow(15, W);
        moveMouse.turnRight();
        moveMouse.movearrow(1, W);
        moveMouse.turnRight();
        moveMouse.movearrow(1, W);
    }

    return 0;
}
