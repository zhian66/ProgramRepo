#include "Chess.h"

Pawn::Pawn() {
    if(color == 0) pos = std::make_pair(0, 6);
    else if(color == 1) pos = std::make_pair(0, 3);
    else pos = std::make_pair(0, 0);
    id = 7;
}

Pawn::Pawn(const Pawn& pawn) {
    pos = pawn.pos;
    color = pawn.color;
    isActive = pawn.isActive;
    id = pawn.id;
}

Pawn::Pawn(const int& X, const int& Y) {
    pos = std:: make_pair(X, Y);
    color = 2;
    isActive = false;
    id = 7;
}

Pawn::Pawn(const std::pair<int, int>& Pos) {
    pos = Pos;
    color = 2;
    isActive = false;
    id = 7;
}

Pawn::Pawn(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
    isActive = true;
    id = 7;
}

Pawn::~Pawn() {
    
}

Pawn& Pawn::operator= (const Pawn& pawn) {
    pos = pawn.pos;
    color = pawn.color;
    isActive = pawn.isActive;
    id = pawn.id;
    return *this;
}

Pawn& Pawn::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>> Pawn::getSuggestion(std::vector<std::vector<Chess*>> board){
    std::pair<int, int> sug;
    std::vector<std::pair<int, int>> sugList;
    bool throghRiver = false;

    if (color == 1) {                       // Red    
        if (pos.second < 5)
            throghRiver = true;
        if (pos.second != 0) {    // up
            sug = pos;
            sug.second--;
            sugList.push_back(sug);
        }
    } else {                                // Black
        if (pos.second > 4)
            throghRiver = true;
        if (pos.second != 9) {    // down
            sug = pos;
            sug.second++;
            sugList.push_back(sug);
        }

    }
    if (throghRiver) {
        if (pos.first != 8 && inEnemy()) {    // right
            sug = pos;
            sug.first++;
            sugList.push_back(sug);
        }
        if (pos.first != 0 && inEnemy()) {    // left
            sug = pos;
            sug.first--;
            sugList.push_back(sug);
        }
    }
    return sugList;
}
