#include <Windows.h>
#include <iostream>

class moveMouse{
    int X = 1680;
    //
public:
    void init();
    void lookDown();
    void lookUp();
    void centerY();
};

void moveMouse::init(){
    int fullRotation = X * 1.43;
    int halfRotation = fullRotation / 2;
    int hold = X / 2;
    int stepRightDown = hold + 1;
    int stepLeftUp = hold - 1;
}
void moveMouse::lookDown(){
    init();
    for(int i = 0; i < fullRotation; i++){
        Sleep(20);
        SetCursorPos( hold, stepRightDown );
    }
}
void moveMouse::lookUp(){
    init();
    for(int i = 0; i < fullRotation; i++){
        Sleep(20);
        SetCursorPos( hold, stepLeftUp );
    }
}
void centerY(){
    lookDown();
    for(int i = 0; i < halfRotation; i++){
        Sleep(20);
        SetCursorPos( hold, stepLeftUp );
    }
}

int main()
{
    Sleep(3000);
    moveMouse::lookDown();
    return 0;
}
