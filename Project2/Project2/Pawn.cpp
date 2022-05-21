#include "Chess.h"

Pawn::Pawn() {
    //  how do you know if it is player1 or not?
    if(Player1) pos = std::make_pair(0, 6);
    else pos = std::make_pair(0, 3);
    //  how do you deal with X?
}

Pawn::Pawn(const Pawn& pawn) {
    pos = pawn.pos;
}

Pawn::Pawn(const int& X, const int& Y) {
    pos = std:: make_pair(X, Y);
}

Pawn::Pawn(const std::pair<int, int>& Pos) {
    pos = Pos;
}

Pawn::Pawn(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
}

Pawn::~Pawn() {
    
}

Pawn& Pawn::operator= (const Pawn& pawn) {
    pos = pawn.pos;
    return *this;
}

Pawn& Pawn::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>>& Pawn::getSuggestion() {
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    //  how do you know if it is player1 or not?
    if(pos.second != 0 && player1) {    // up
        sug = pos;
        sug.second--;
        sugList.push_back(sug);
    }
    if(player2 && pos.second != 9) {    // down
        sug = pos;
        sug.second++;
        sugList.push_back(sug);
    }
    // how do you know if you are in enemy camp?
    if(pos.first != 8 && inEnemy) {    // right
        sug = pos;
        sug.first++;
        sugList.push_back(sug);
    }
    if(pos.first != 0 && inEnemy) {    // left
        sug = pos;
        sug.first--;
        sugList.push_back(sug);
    }
    return sugList;
}
