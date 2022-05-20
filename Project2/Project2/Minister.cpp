#include "Chess.h"

Minister::Minister() {
    //  how do you know if it is player1 or not?
    if(Player1) pos = std::make_pair(2, 9);
    else pos = std::make_pair(2, 0);
    //  how do you deal with X?
}

Minister::Minister(const Minister& minister) {
    pos = minister.pos;
}

Minister::Minister(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
}

Minister::Minister(const std::pair<int, int>& Pos) {
    pos = Pos;
}

Minister::~Minister() {
    
}

Minister& Minister::operator= (const Minister& minister) {
    pos = minister.pos;
    return *this;
}

Minister& Minister::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>>& Minister::getSuggestion() {
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    {
        //  up right
        sug = pos;
        sug.first += 2;
        sug.second -= 2;
        if(sug.first <= 8 && sug.second >= 0 && !inEnemy) sugList.push_back(sug);
    }
    {
        //  down right
        sug = pos;
        sug.first += 2;
        sug.second += 2;
        if(sug.first <= 8 && sug.second <= 9 && !inEnemy) sugList.push_back(sug);
    }
    {
        //  up left
        sug = pos;
        sug.first -= 2;
        sug.second -= 2;
        if(sug.first >= 0 && sug.second >= 0 && !inEnemy) sugList.push_back(sug);
    }
    {
        //  down left
        sug = pos;
        sug.first -= 2;
        sug.second += 2;
        if(sug.first >= 0 && sug.second <= 9 && !inEnemy) sugList.push_back(sug);
    }
    return sugList;
}
