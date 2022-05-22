#include "Chess.h"

Horse::Horse() {
    id = 4;
}

Horse::Horse(const Horse& horse) {
    pos = horse.pos;
    color = horse.color;
    isActive = horse.isActive;
    id = horse.id;
}

Horse::Horse(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
    color = 2;
    isActive = false;
    id = 4;
}

Horse::Horse(const std::pair<int, int>& Pos) {
    pos = Pos;
    color = 2;
    isActive = false;
    id = 4;
}

Horse::Horse(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
    isActive = true;
    id = 4;
}

Horse::~Horse() {
    
}

Horse& Horse::operator= (const Horse& horse) {
    pos = horse.pos;
    color = horse.color;
    isActive = horse.isActive;
    id = horse.id;
    return *this;
}

Horse& Horse::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>> Horse::getSuggestion(std::vector<std::vector<Chess*>> board){
    std::vector<std::pair<int, int>> sugList;
    std::pair<int, int> sug;
    {
        //  up and down
        for (int y = -1; y <= 1; y += 2) {
            sug = pos;
            sug.second += 2 * y;
            if (sug.second > 9 || sug.second < 0)
                continue;
            if (board[sug.first][sug.second - y]->isActive)
                continue;
            
            for (int x = -1; x <= 1; x += 2) {
                if (sug.first + x > 8 || sug.first + x < 0)
                    continue;
                if (board[sug.first + x][sug.second]->isActive)
                    if (board[sug.first + x][sug.second]->color == color)
                        continue;
                sugList.push_back(std::make_pair(sug.first + x, sug.second));
            }
        }
    }
    {
        // left and right
        for (int x = -1; x <= 1; x += 2) {
            sug = pos;
            sug.first += 2 * x;
            if (sug.first < 0 || sug.first > 8)
                continue;
            if (board[sug.first - x][sug.second]->isActive)
                continue;
            for (int y = -1; y <= 1; y += 2) {
                if (sug.second + y > 9 || sug.second + y < 0)
                    continue;
                if (board[sug.first][sug.second + y]->isActive)
                    if (board[sug.first][sug.second + y]->color == color)
                        continue;
                sugList.push_back(std::make_pair(sug.first, sug.second + y));
            }
        }
    }
    return sugList;
}
