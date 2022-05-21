//  Created by RinKawano

#ifndef Board_h
#define Board_h

#include <array>
#include <utility>
#include "Chess.h"
using namespace std;

class Board {
private:
    array<array<Chess&, 10>, 9> board;   // player_1 will be down side, and player_2 will be upper side
    
public:
    Board();
    Board(const Board& brd);
    ~Board();
    Board& operator= (const Board& brd);
    std::pair<int, int> posChanging(std::pair<int, int> pos);
};

#endif /* Board_h */