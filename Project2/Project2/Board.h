//  Created by RinKawano

#ifndef Board_h
#define Board_h

#include <vector>
#include <utility>
#include <string>
#include "Chess.h"

class Board {
private:
    std::vector<std::vector<std::string>> nameTable;

public:
    Board();
    Board(const Board& brd);
    ~Board();
    Board& operator= (const Board& brd);

    std::vector<Chess*> initBoard();
    std::pair<int, int> posChanging(int x, int y);

    std::vector<std::vector<Chess*>> board;   // player_1 will be down side, and player_2 will be upper side
    std::vector<std::pair<int, int>> sugList;
};

#endif /* Board_h */
