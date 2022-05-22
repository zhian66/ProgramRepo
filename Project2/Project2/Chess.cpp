#include "Chess.h"

Chess::Chess() {
    pos = std::make_pair(0, 0);
    color = 2;
    isActive = false;
}

Chess::Chess(const Chess& piece) {
    pos = piece.pos;
    color = piece.color;
    isActive = piece.isActive;
    id = piece.id;
}

Chess::Chess(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
    color = 2;
    isActive = false;
}

Chess::Chess(const std::pair<int, int>& Pos) {
    pos = Pos;
    color = 2;
    isActive = false;
}

Chess::Chess(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
    isActive = true;
}


Chess::~Chess() {
    
}

Chess& Chess::operator= (const Chess& piece) {
    pos = piece.pos;
    color = piece.color;
    isActive = piece.isActive;
    id = piece.id;
    return *this;
}

Chess& Chess::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

void Chess::go(const int& X, const int& Y) {
    pos.first = X;
    pos.second = Y;
    return;
}

void Chess::go(const std::pair<int, int>& Pos) {
    pos = Pos;
    return;
}

void Chess::stay() {
    return;
}

void Chess::kick() {
    return;
}

std::vector<std::pair<int, int>> Chess::getSuggestion() {
    std::vector<std::pair<int, int>> sugList;
    return sugList;
}


bool Chess::inEnemy() {
    if(color == 0) {
        if(0 <= pos.first && pos.first <= 8) {
            if(0 <= pos.second && pos.second <= 4) return true;
        }
    }
    else if(color == 1) {
        if(0 <= pos.first && pos.first <= 8) {
            if(5 <= pos.second && pos.second <= 9) return true;
        }
    }
    return false;
}


Empty::Empty() {
    isActive = false;
}

std::vector<std::pair<int, int>> Empty::getSuggestion() {
    std::vector<std::pair<int, int>> sugList;
    return sugList;
}
