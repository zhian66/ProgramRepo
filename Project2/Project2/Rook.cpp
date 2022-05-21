#include "Chess.h"

Rook::Rook() {
    
}

Rook::Rook(const Rook& rook) {
    pos = rook.pos;
    color = rook.color;
    isActive = rook.isActive;
}

Rook::Rook(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
    color = 2;
    isActive = false;
}

Rook::Rook(const std::pair<int, int>& Pos) {
    pos = Pos;
    color = 2;
    isActive = false;
}

Rook::Rook(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
    isActive = true;
}

Rook::~Rook() {
    
}

Rook& Rook::operator= (const Rook& rook) {
    pos = rook.pos;
    color = rook.color;
    isActive = rook.isActive;
    return *this;
}

Rook& Rook::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>>& Rook::getSuggestion() override {
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
