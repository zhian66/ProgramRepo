#include "Chess.h"

King::King() {
    pos = std::make_pair(0, 0);
}

King::King(const King& king) {
    pos = king.pos;
}

King::King(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
}

King::King(const std::pair<int, int>& Pos) {
    pos = Pos;
}

King::~King() {
    
}

King& King::operator= (const King& king) {
    pos = king.pos;
    return *this;
}

King& King::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

void King::getSuggestion() {
    
}
