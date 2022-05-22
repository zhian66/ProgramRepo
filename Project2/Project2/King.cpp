#include "Chess.h"

King::King() {
    if(color == 0) pos = std::make_pair(4, 9);
    else if(color == 1) pos = std::make_pair(4, 0);
    else pos = std::make_pair(0, 0);
    this->id = 1;
}

King::King(const King& king) {
    pos = king.pos;
    color = king.color;
    isActive = king.isActive;
    this->id = king.id;
}

King::King(const int& X, const int& Y) {
    pos = std::make_pair(X, Y);
    color = 2;
    isActive = false;
    this->id = 1;
}

King::King(const std::pair<int, int>& Pos) {
    pos = Pos;
    color = 2;
    isActive = false;
    this->id = 1;
}

King::King(const int& X, const int& Y, int color) {
    pos = std::make_pair(X, Y);
    this->color = color;
    isActive = true;
    this->id = 1;
}

King::~King() {
    
}

King& King::operator= (const King& king) {
    pos = king.pos;
    color = king.color;
    isActive = king.isActive;
    this->id = king.id;
    return *this;
}

King& King::operator= (const std::pair<int, int>& Pos) {
    pos = Pos;
    return *this;
}

std::vector<std::pair<int, int>> King::getSuggestion(std::vector<std::vector<Chess*>> board){
    std::pair<int, int> tmp = pos;
    std::pair<int, int> sug;
    std::vector<std::pair<int, int>> sugList;
    if (color == 1) tmp.second -= 7;
    

    if(tmp.first != 5) {    // right
        sug = pos;
        sug.first++;
        if (!board[sug.first][sug.second]->isActive)
            sugList.push_back(sug);
    }
    
    if(tmp.first != 3) {    // left
        sug = pos;
        sug.first--;
        if (!board[sug.first][sug.second]->isActive)
            sugList.push_back(sug);
    }
    bool meetKing = false;
    if (color == 1) {
        for (int Y = pos.second - 1; Y >= 0; Y--) {
            if (board[pos.first][Y]->isActive) {
                if (board[pos.first][Y]->id != 1)
                    break;
                else {
                    sugList.push_back(std::make_pair(pos.first, Y));
                    meetKing = true;
                }
            }
        }
        if (!meetKing) {
            if (tmp.second != 0 && tmp.second != 7) {    // up
                sug = pos;
                sug.second--;
                if (!board[sug.first][sug.second]->isActive)
                    sugList.push_back(sug);
            }
        }
        if (tmp.second != 2 && tmp.second != 9) {    // down
            sug = pos;
            sug.second++;
            if (!board[sug.first][sug.second]->isActive)
                sugList.push_back(sug);
        }

    } else {
        for (int Y = pos.second + 1; Y < 10; Y++) {
            if (board[pos.first][Y]->isActive) {
                if (board[pos.first][Y]->id != 1)
                    break;
                else {
                    sugList.push_back(std::make_pair(pos.first, Y));
                    meetKing = true;
                }
            }
        }

        if (!meetKing) {
            if (tmp.second != 2 && tmp.second != 9) {    // down
                sug = pos;
                sug.second++;
                if (!board[sug.first][sug.second]->isActive)
                    sugList.push_back(sug);
            }
        }
        if (tmp.second != 0 && tmp.second != 7) {    // up
            sug = pos;
            sug.second--;
            if (!board[sug.first][sug.second]->isActive)
                sugList.push_back(sug);
        }
        

    }

    
    return sugList;
}
