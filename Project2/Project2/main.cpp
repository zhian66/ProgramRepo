#include <iostream>
#include <string>
#include "GameManager.h"

int main() {
    GameManager GM;
    while (GM.isRunning()) {        // if the window is opened
        switch (GM.getStatus()) {
            case 0:                     // defult menu
                GM.menu();
                break;
            case 1:                     // new game
                GM.initGame();
                GM.playGame();
                break;
            case 2:                     // load game
                GM.loadGame();
                GM.playGame();
                break;
            default:
                break;
        }
    }
    return 0;
}

