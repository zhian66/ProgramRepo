#include "Chess.h"

Horse::Horse() {
    //  how do you know if it is player1 or not?
    if(Player1) pos = std::make_pair(1, 9);
    else pos = std::make_pair(1, 0);
    //  how do you deal with X?
}

Horse::Horse(const Horse& horse) {
    pos = horse.pos;
}

Horse::Horse(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
}

Horse::Horse(const std::pair<int, int>& Pos) {
    pos = Pos;
}

Horse::~Horse() {
    
}

Horse& Horse::operator= (const Horse& horse) {
    pos = horse.pos;
    return *this;
}

Horse& Horse::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>>& Horse::getSuggestion() override {
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    {
        //  up right1
        sug = pos;
        sug.first += 1;
        sug.second -= 2;
        if(sug.first <= 8 && sug.second >= 0) sugList.push_back(sug);
    }
    {
        //  up right2
        sug = pos;
        sug.first += 2;
        sug.second -= 1;
        if(sug.first <= 8 && sug.second >= 0) sugList.push_back(sug);
    }
    {
        //  down right1
        sug = pos;
        sug.first += 2;
        sug.second += 1;
        if(sug.first <= 8 && sug.second <= 9) sugList.push_back(sug);
    }
    {
        //  down right2
        sug = pos;
        sug.first += 1;
        sug.second += 2;
        if(sug.first <= 8 && sug.second <= 9) sugList.push_back(sug);
    }
    {
        //  up left1
        sug = pos;
        sug.first -= 1;
        sug.second -= 2;
        if(sug.first >= 0 && sug.second >= 0) sugList.push_back(sug);
    }
    {
        //  up left2
        sug = pos;
        sug.first -= 2;
        sug.second -= 1;
        if(sug.first >= 0 && sug.second >= 0) sugList.push_back(sug);
    }
    {
        //  down left1
        sug = pos;
        sug.first -= 2;
        sug.second += 1;
        if(sug.first >= 0 && sug.second <= 9) sugList.push_back(sug);
    }
    {
        //  down left2
        sug = pos;
        sug.first -= 1;
        sug.second += 2;
        if(sug.first >= 0 && sug.second <= 9) sugList.push_back(sug);
    }
    return sugList;
}
