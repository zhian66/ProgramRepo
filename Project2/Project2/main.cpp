#include <iostream>
#include <string>
#include "GameManager.h"

int main() {
    GameManager GM;
    while (GM.isRunning()) {
        switch (GM.getStatus()) {   // if the window is opened
        case 0:                     // defult menu
            GM.menu();
        case 1:                      // new game
            GM.initGame();
            GM.playGame(); break;
        case 2:                     // load game
            GM.LoadGame();
            GM.playGame(); break;
        }
    }
    return 0;
}

