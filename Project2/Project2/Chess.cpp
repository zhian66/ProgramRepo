#include "Chess.h"

Chess::Chess() {
    pos = std::make_pair(0, 0);
}

Chess::Chess(const Chess& piece) {
    pos = piece.pos;
}

Chess::Chess(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
}

Chess::Chess(const std::pair<int, int>& Pos) {
    pos = Pos;
}

Chess::~Chess() {
    
}

Chess& Chess::operator= (const Chess& piece) {
    pos = piece.pos;
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
