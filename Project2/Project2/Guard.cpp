#include "Chess.h"

Guard::Guard() {
    id = 2;
}

Guard::Guard(const Guard& guard) {
    pos = guard.pos;
    color = guard.color;
    isActive = guard.isActive;
    id = guard.id;
}

Guard::Guard(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
    color = 2;
    isActive = false;
    id = 2;
}

Guard::Guard(const std::pair<int, int>& Pos) {
    pos = Pos;
    color = 2;
    isActive = false;
    id = 2;
}

Guard::Guard(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
    isActive = true;
    id = 2;
}

Guard::~Guard() {
    
}

Guard& Guard::operator= (const Guard& guard) {
    pos = guard.pos;
    color = guard.color;
    isActive = guard.isActive;
    id = guard.id;
    return *this;
}

Guard& Guard::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>> Guard::getSuggestion(){
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    {
        //  up right
        sug = pos;
        sug.first += 1;
        sug.second -= 1;
        if(sug.first <= 5 && sug.second >= 0) sugList.push_back(sug);
    }
    {
        //  down right
        sug = pos;
        sug.first += 1;
        sug.second += 1;
        if(sug.first <= 5 && sug.second <= 2) sugList.push_back(sug);
    }
    {
        //  up left
        sug = pos;
        sug.first -= 1;
        sug.second -= 1;
        if(sug.first >= 3 && sug.second >= 0) sugList.push_back(sug);
    }
    {
        //  down left
        sug = pos;
        sug.first -= 1;
        sug.second += 1;
        if(sug.first >= 3 && sug.second <= 2) sugList.push_back(sug);
    }
    return sugList;
}
