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

std::vector<std::pair<int, int>> Guard::getSuggestion(std::vector<std::vector<Chess*>> board){
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    std::pair<int, int> tmp = pos;
    if (color == 1) tmp.second -= 7;
    {
        //  up right
        if (tmp.first + 1 <= 5 && tmp.second - 1 >= 0) {
            sug = pos;
            sug.first += 1;
            sug.second -= 1;
            if (!(board[sug.first][sug.second]->isActive &&
                board[sug.first][sug.second]->color == color))
                sugList.push_back(sug);
        }
    }
    {
        //  down right
        if (tmp.first + 1 <= 5 && tmp.second + 1 <= 2) {
            sug = pos;
            sug.first += 1;
            sug.second += 1;
            if (!(board[sug.first][sug.second]->isActive &&
                board[sug.first][sug.second]->color == color))
                sugList.push_back(sug);
        }
    }
    {
        //  up left
        if (tmp.first - 1 >= 3 && tmp.second - 1 >= 0) {
            sug = pos;
            sug.first -= 1;
            sug.second -= 1;
            if (!(board[sug.first][sug.second]->isActive &&
                board[sug.first][sug.second]->color == color))
                sugList.push_back(sug);
        }
    }
    {
        //  down left
        if (tmp.first - 1 >= 3 && tmp.second + 1 <= 2) {
            sug = pos;
            sug.first -= 1;
            sug.second += 1;
            if (!(board[sug.first][sug.second]->isActive &&
                board[sug.first][sug.second]->color == color))
                sugList.push_back(sug);
        }
    }
    return sugList;
}
