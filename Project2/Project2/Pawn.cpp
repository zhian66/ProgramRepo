#include "Chess.h"

Pawn::Pawn() {
    pos = std::make_pair(0, 0);
}

Pawn::Pawn(const Pawn& pawn) {
    pos = pawn.pos;
}

Pawn::Pawn(const int& X, const int& Y) {
    pos = std:: make_pair(X, Y);
}

Pawn::Pawn(const std::pair<int, int>& Pos) {
    pos = Pos;
}

Pawn::Pawn(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
}

Pawn::~Pawn() {
    
}

Pawn& Pawn::operator= (const Pawn& pawn) {
    pos = pawn.pos;
    return *this;
}

Pawn& Pawn::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

void Pawn::getSuggestion() {
    return;
}
