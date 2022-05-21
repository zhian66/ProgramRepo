#include "Chess.h"

Minister::Minister() {
    pos = std::make_pair(0, 0);
}

Minister::Minister(const Minister& minister) {
    pos = minister.pos;
}

Minister::Minister(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
}

Minister::Minister(const std::pair<int, int>& Pos) {
    pos = Pos;
}

Minister::Minister(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
}

Minister::~Minister() {
    
}

Minister& Minister::operator= (const Minister& minister) {
    pos = minister.pos;
    return *this;
}

Minister& Minister::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

void Minister::getSuggestion() {
    return;
}
