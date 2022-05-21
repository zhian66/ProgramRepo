#include "Chess.h"

King::King() {
    if(color == 0) pos = std::make_pair(4, 9);
    else if(color == 1) pos = std::make_pair(4, 0);
    else pos = std::make_pair(0, 0);
}

King::King(const King& king) {
    pos = king.pos;
    color = king.color;
    isActive = king.isActive;
}

King::King(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
    color = 2;
    isActive = false;
}

King::King(const std::pair<int, int>& Pos) {
    pos = Pos;
    color = 2;
    isActive = false;
}

King::King(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
    isActive = true;
}

King::~King() {
    
}

King& King::operator= (const King& king) {
    pos = king.pos;
    color = king.color;
    isActive = king.isActive;
    return *this;
}

King& King::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>>& King::getSuggestion(){
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    if(pos.second != 0 && pos.second != 7) {    // up
        sug = pos;
        sug.second--;
        sugList.push_back(sug);
    }
    if(pos.first != 5) {    // right
        sug = pos;
        sug.first++;
        sugList.push_back(sug);
    }
    if(pos.second != 2 && pos.second != 9) {    // down
        sug = pos;
        sug.second++;
        sugList.push_back(sug);
    }
    if(pos.first != 3) {    // left
        sug = pos;
        sug.first--;
        sugList.push_back(sug);
    }
    return sugList;
}
