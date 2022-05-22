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

std::vector<std::pair<int, int>> Minister::getSuggestion(std::vector<std::vector<Chess*>> board){
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    std::pair<int, int> boundary(0, 9);
    
    if (color == 1)
        boundary.first = 5;
    else
        boundary.second = 4;
    {
        //  up right
        sug = pos;
        sug.first += 2;
        sug.second -= 2;
        if(sug.first <= 8 && sug.second >= boundary.first)
            if (!board[pos.first + 1][pos.second - 1]->isActive)
                sugList.push_back(sug);
    }
    {
        //  down right
        sug = pos;
        sug.first += 2;
        sug.second += 2;
        if(sug.first <= 8 && sug.second <= boundary.second)
            if (!board[pos.first + 1][pos.second + 1]->isActive)
                sugList.push_back(sug);
    }
    {
        //  up left
        sug = pos;
        sug.first -= 2;
        sug.second -= 2;
        if(sug.first >= 0 && sug.second >= boundary.first)
            if (!board[pos.first - 1][pos.second - 1]->isActive)
                sugList.push_back(sug);
    }
    {
        //  down left
        sug = pos;
        sug.first -= 2;
        sug.second += 2;
        if(sug.first >= 0 && sug.second <= boundary.second)
            if (!board[pos.first - 1][pos.second + 1]->isActive)
                sugList.push_back(sug);
    }
    return sugList;
}
