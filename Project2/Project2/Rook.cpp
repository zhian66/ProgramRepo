#include "Chess.h"

Rook::Rook() {
    pos = std::make_pair(0, 0);
}

Rook::Rook(const Rook& rook) {
    pos = rook.pos;
}

Rook::Rook(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
}

Rook::Rook(const std::pair<int, int>& Pos) {
    pos = Pos;
}

Rook::Rook(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
}

Rook::~Rook() {
    
}

Rook& Rook::operator= (const Rook& rook) {
    pos = rook.pos;
    return *this;
}

Rook& Rook::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

void Rook::getSuggestion() {
    return;
}
