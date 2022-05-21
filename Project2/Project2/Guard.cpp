#include "Chess.h"

Guard::Guard() {
    pos = std::make_pair(0, 0);
}

Guard::Guard(const Guard& guard) {
    pos = guard.pos;
}

Guard::Guard(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
}

Guard::Guard(const std::pair<int, int>& Pos) {
    pos = Pos;
}

Guard::Guard(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
}

Guard::~Guard() {
    
}

Guard& Guard::operator= (const Guard& guard) {
    pos = guard.pos;
    return *this;
}

Guard& Guard::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

void Guard::getSuggestion() {
    
}
