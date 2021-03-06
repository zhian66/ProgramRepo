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

std::vector<std::pair<int, int>> Cannon::getSuggestion(std::vector<std::vector<Chess*>> board){
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    bool jump = false;
    for(int Y = pos.second - 1; Y >= 0; Y--) {  // up
        sug = std::make_pair(pos.first, Y);
        if (!jump) {
            if (board[sug.first][sug.second]->isActive)
                jump = true;
            else
                sugList.push_back(sug);
        } else {
            if (board[sug.first][sug.second]->isActive)
                if (board[sug.first][sug.second]->color != color) {
                    sugList.push_back(sug);
                    break;
                }
        }
            
    }

    jump = false;
    for(int Y = pos.second + 1; Y <= 9; Y++) {  // down
        sug = std::make_pair(pos.first, Y);
        if (!jump) {
            if (board[sug.first][sug.second]->isActive)
                jump = true;
            else
                sugList.push_back(sug);
        } else {
            if (board[sug.first][sug.second]->isActive)
                if (board[sug.first][sug.second]->color != color) {
                    sugList.push_back(sug);
                    break;
                }
        }
    }

    jump = false;
    for(int X = pos.first - 1; X >= 0; X--) {  // left
        sug = std::make_pair(X, pos.second);
        if (!jump) {
            if (board[sug.first][sug.second]->isActive)
                jump = true;
            else sugList.push_back(sug);
        } else {
            if (board[sug.first][sug.second]->isActive)
                if (board[sug.first][sug.second]->color != color) {
                    sugList.push_back(sug);
                    break;
                }
        }
    }

    jump = false;
    for(int X = pos.first + 1; X <= 8; X++) {  // right
        sug = std::make_pair(X, pos.second);
        if (!jump) {
            if (board[sug.first][sug.second]->isActive)
                jump = true;
            else sugList.push_back(sug);
        } else {
            if (board[sug.first][sug.second]->isActive)
                if (board[sug.first][sug.second]->color != color) {
                    sugList.push_back(sug);
                    break;
                }
        }
    }
    return sugList;
}
