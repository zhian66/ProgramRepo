#include "Chess.h"

Rook::Rook() {
    id = 5;
}

Rook::Rook(const Rook& rook) {
    pos = rook.pos;
    color = rook.color;
    isActive = rook.isActive;
    id = rook.id;
}

Rook::Rook(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
    color = 2;
    isActive = false;
    id = 5;
}

Rook::Rook(const std::pair<int, int>& Pos) {
    pos = Pos;
    color = 2;
    isActive = false;
    id = 5;
}

Rook::Rook(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
    isActive = true;
    id = 5;
}

Rook::~Rook() {
    
}

Rook& Rook::operator= (const Rook& rook) {
    pos = rook.pos;
    color = rook.color;
    isActive = rook.isActive;
    id = rook.id;
    return *this;
}

Rook& Rook::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>> Rook::getSuggestion(std::vector<std::vector<Chess*>> board){
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    for(int Y = pos.second - 1; Y >= 0; Y--) {  // up
        if (board[pos.first][Y]->isActive)
            if (board[pos.first][Y]->color == color)
                break;
            else
                sugList.push_back(std::make_pair(pos.first, Y));

        sug = std::make_pair(pos.first, Y);
        sugList.push_back(sug);
    }
    for(int Y = pos.second + 1; Y <= 9; Y++) {  // down
        if (board[pos.first][Y]->isActive)
            if (board[pos.first][Y]->color == color)
                break;
            else
                sugList.push_back(std::make_pair(pos.first, Y));

        sug = std::make_pair(pos.first, Y);
        sugList.push_back(sug);
    }
    for(int X = pos.first - 1; X >= 0; X--) {  // left
        if (board[X][pos.second]->isActive)
            if (board[X][pos.second]->color == color)
                break;
            else
                sugList.push_back(std::make_pair(X, pos.second));

        sug = std::make_pair(X, pos.second);
        sugList.push_back(sug);
    }
    for(int X = pos.first + 1; X <= 8; X++) {  // right
        if (board[X][pos.second]->isActive)
            if (board[X][pos.second]->color == color)
                break;
            else
                sugList.push_back(std::make_pair(X, pos.second));
        sug = std::make_pair(X, pos.second);
        sugList.push_back(sug);
    }
    return sugList;
}
