#include "Chess.h"

King::King() {
    //  how do you know if it is player1 or not?
    if(Player1) pos = std::make_pair(4, 9);
    else pos = std::make_pair(4, 0);
}

King::King(const King& king) {
    pos = king.pos;
}

King::King(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
}

King::King(const std::pair<int, int>& Pos) {
    pos = Pos;
}

King::King(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
}

King::~King() {
    
}

King& King::operator= (const King& king) {
    pos = king.pos;
    return *this;
}

King& King::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>>& King::getSuggestion() {
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
