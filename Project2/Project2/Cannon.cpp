#include "Chess.h"

Cannon::Cannon() {
    pos = std::make_pair(0, 0);
}

Cannon::Cannon(const Cannon& cannon) {
    pos = cannon.pos;
}

Cannon::Cannon(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
}

Cannon::Cannon(const std::pair<int, int>& Pos) {
    pos = Pos;
}

Cannon::Cannon(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
}

Cannon::~Cannon() {
    
}

Cannon& Cannon::operator= (const Cannon& cannon) {
    pos = cannon.pos;
    return *this;
}

Cannon& Cannon::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

void Cannon::getSuggestion() {
    return;
}
