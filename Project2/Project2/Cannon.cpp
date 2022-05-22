#include "Chess.h"

Cannon::Cannon() {
    id = 6;
}

Cannon::Cannon(const Cannon& cannon) {
    pos = cannon.pos;
    color = cannon.color;
    isActive = cannon.isActive;
    id = cannon.id;
}

Cannon::Cannon(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
    color = 2;
    isActive = false;
    id = 6;
}

Cannon::Cannon(const std::pair<int, int>& Pos) {
    pos = Pos;
    color = 2;
    isActive = false;
    id = 6;
}

Cannon::Cannon(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
    isActive = true;
    id = 6;
}

Cannon::~Cannon() {
    
}

Cannon& Cannon::operator= (const Cannon& cannon) {
    pos = cannon.pos;
    color = cannon.color;
    isActive = cannon.isActive;
    id = cannon.id;
    return *this;
}

Cannon& Cannon::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>> Cannon::getSuggestion(){
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
