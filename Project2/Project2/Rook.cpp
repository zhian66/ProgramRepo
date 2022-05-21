#include "Chess.h"

Rook::Rook() {
    //  how do you know if it is player1 or not?
    if(Player1) pos = std::make_pair(0, 9);
    else pos = std::make_pair(0, 0);
    //  how do you deal with X?
}

Rook::Rook(const Rook& rook) {
    pos = rook.pos;
}

Rook::Rook(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
}

Rook::Rook(const std::pair<int, int>& Pos) {
    pos = Pos;
}

Rook::Rook(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
}

Rook::~Rook() {
    
}

Rook& Rook::operator= (const Rook& rook) {
    pos = rook.pos;
    return *this;
}

Rook& Rook::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>>& Rook::getSuggestion() {
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    for(int Y = pos.second; Y >= 0; Y--) {  // up
        sug = std::make_pair(pos.first, Y);
        sugList.push_back(sug);
    }
    for(int Y = pos.second; Y <= 9; Y++) {  // down
        sug = std::make_pair(pos.first, Y);
        sugList.push_back(sug);
    }
    for(int X = pos.first; X >= 0; X--) {  // left
        sug = std::make_pair(X, pos.first);
        sugList.push_back(sug);
    }
    for(int X = pos.first; X <= 8; X++) {  // right
        sug = std::make_pair(X, pos.first);
        sugList.push_back(sug);
    }
    return sugList;
}
