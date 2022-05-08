#include <Windows.h>
#include <iostream>

int main()
{
    Sleep(3000);
    SetCursorPos(840,525);
    /*while(1){
        Sleep(1);
        SetCursorPos(840,525);
    }*/
    int resolutionX = 1680;
    int resolutionY = 1050;
    int ammountOfMovesX = resolutionX * 1.43;
    int ammountOfMovesY = resolutionX * 0.715;
    int holdX = resolutionX / 2;
    int holdY = resolutionY / 2;
    int oneStepX = holdX + 1;
    int oneStepY = holdY - 1;
    for(int i = 0; i < ammountOfMovesX; i++){
        Sleep(20);
        if (i < ammountOfMovesY){
            SetCursorPos( oneStepX, oneStepY );
        }
        else
            SetCursorPos( oneStepX, holdY+1 );
    }
    /*for(int j = 0; j < ammountOfMovesY; i++){
        Sleep(20);
        SetCursorPos( holdX, oneStepY );
    }*/
    return 0;
}
