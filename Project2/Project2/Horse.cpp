#include "Chess.h"

Horse::Horse() {
    pos = std::make_pair(0, 0);
}

Horse::Horse(const Horse& horse) {
    pos = horse.pos;
}

Horse::Horse(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
}

Horse::Horse(const std::pair<int, int>& Pos) {
    pos = Pos;
}

Horse::Horse(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
}

Horse::~Horse() {
    
}

Horse& Horse::operator= (const Horse& horse) {
    pos = horse.pos;
    return *this;
}

Horse& Horse::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

void Horse::getSuggestion() {
    return;
}
