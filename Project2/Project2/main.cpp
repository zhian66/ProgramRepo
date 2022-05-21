#include <iostream>
#include <string>
#include "GameManager.h"

int main() {
    GameManager GM;
    while (GM.isRunning()) {
        switch (GM.getStatus()) {
        case 0:
            GM.menu();
            GM.playGame(); break;
        case 1:
            GM.initGame();
            GM.playGame(); break;
        case 2:
            GM.LoadGame();
            GM.playGame(); break;
        }
    }
    return 0;
}

