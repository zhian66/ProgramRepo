#include <iostream>
#include <string>
#include "GameManager.h"

int main() {
    GameManager GM;
    while (GM.isRunning()) {
        GM.menu();
    }
    return 0;
}

