#include "Chess.h"

Minister::Minister() {
    id = 3;
}

Minister::Minister(const Minister& minister) {
    pos = minister.pos;
    color = minister.color;
    isActive = minister.isActive;
    id = minister.id;
}

Minister::Minister(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
    color = 2;
    isActive = false;
    id = 3;
}

Minister::Minister(const std::pair<int, int>& Pos) {
    pos = Pos;
    color = 2;
    isActive = false;
}

Minister::Minister(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
    isActive = true;
    id = 3;
}

Minister::~Minister() {
    
}

Minister& Minister::operator= (const Minister& minister) {
    pos = minister.pos;
    color = minister.color;
    isActive = minister.isActive;
    id = minister.id;
    return *this;
}

Minister& Minister::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>> Minister::getSuggestion(){
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    {
        //  up right
        sug = pos;
        sug.first += 2;
        sug.second -= 2;
        if(sug.first <= 8 && sug.second >= 0 && !inEnemy()) sugList.push_back(sug);
    }
    {
        //  down right
        sug = pos;
        sug.first += 2;
        sug.second += 2;
        if(sug.first <= 8 && sug.second <= 9 && !inEnemy()) sugList.push_back(sug);
    }
    {
        //  up left
        sug = pos;
        sug.first -= 2;
        sug.second -= 2;
        if(sug.first >= 0 && sug.second >= 0 && !inEnemy()) sugList.push_back(sug);
    }
    {
        //  down left
        sug = pos;
        sug.first -= 2;
        sug.second += 2;
        if(sug.first >= 0 && sug.second <= 9 && !inEnemy()) sugList.push_back(sug);
    }
    return sugList;
}
