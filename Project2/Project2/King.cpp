#include "Chess.h"

King::King() {
    if(color == 0) pos = std::make_pair(4, 9);
    else if(color == 1) pos = std::make_pair(4, 0);
    else pos = std::make_pair(0, 0);
    this->id = 1;
}

King::King(const King& king) {
    pos = king.pos;
    color = king.color;
    isActive = king.isActive;
    this->id = king.id;
}

King::King(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
    color = 2;
    isActive = false;
    this->id = 1;
}

King::King(const std::pair<int, int>& Pos) {
    pos = Pos;
    color = 2;
    isActive = false;
    this->id = 1;
}

King::King(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
    isActive = true;
    this->id = 1;
}

King::~King() {
    
}

King& King::operator= (const King& king) {
    pos = king.pos;
    color = king.color;
    isActive = king.isActive;
    this->id = king.id;
    return *this;
}

King& King::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>> King::getSuggestion(){
    std::vector<std::pair<int, int>> sugList;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            std::pair<int, int> tmp;
            std::pair<int, int> sug;
            if (color == 1) tmp.first -= 7;
            if (tmp.first + i < 0 || tmp.first + i > 2)
                continue;
            if (tmp.second + j < 3 || tmp.second + j > 5)
                continue;
            sug.first += i;
            sug.second += j;
            sugList.push_back(sug);
        }
    }
    /*
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
    */
    return sugList;
}
