#include "Board.h"

Board::Board() {
    nameTable = { {"Rook"   , "Horse" , "Minister","Guard"  ,"King"   ,"Guard"  ,"Minister","Horse" ,"Rook"   },

                  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

                  {"Empty"  , "Cannon", "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Cannon","Empty"  },

                  { "Pawn"  , "Empty" ,  "Pawn"   ,"Empty"  , "Pawn"  ,"Empty"  , "Pawn"   ,"Empty" , "Pawn"  },

                  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

                  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

                  { "Pawn"  , "Empty" , "Pawn"    ,"Empty"  , "Pawn"  ,"Empty"  , "Pawn"   ,"Empty" , "Pawn"  },

                  {"Empty"  , "Cannon", "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Cannon","Empty"  },

                  {"Empty"  , "Empty" , "Empty"   ,"Empty"  ,"Empty"  ,"Empty"  ,"Empty"   ,"Empty" ,"Empty"  },

                  {"Rook"   , "Horse" , "Minister","Guard"  ,"King"   ,"Guard"  ,"Minister","Horse" ,"Rook"   } };

    initBoard();
}

Board::Board(const Board& brd) {
    board = brd.board;
}

Board::~Board() {

}

Board& Board::operator= (const Board& brd) {
    board = brd.board;
    return *this;
}

std::vector<Chess> Board::initBoard() {
    board.resize(10);
    for (int i = 0; i < 10; i++)
        board[i].resize(9);
    std::vector<Chess> on_board;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            // color 0 is black, 1 is red
            int color = i < 5 ? 1 : 0;
            if (nameTable[i][j] == "Empty") {
                Chess Empty;
                Empty.isActive = false;
                board[i][j] = Empty;
                continue;
            } else if (nameTable[i][j] == "King") {
                board[i][j] = King(i, j, color);
            } else if (nameTable[i][j] == "Guard") {
                board[i][j] = Guard(i, j, color);
            } else if (nameTable[i][j] == "Minister") {
                board[i][j] = Minister(i, j, color);
            } else if (nameTable[i][j] == "Horse") {
                board[i][j] = Horse(i, j, color);
            } else if (nameTable[i][j] == "Rook") {
                board[i][j] = Rook(i, j, color);
            } else if (nameTable[i][j] == "Cannon") {
                board[i][j] = Cannon(i, j, color);
            } else if (nameTable[i][j] == "Pawn") {
                board[i][j] = Pawn(i, j, color);
            }
            on_board.push_back(board[i][j]);
        }
    }
    return on_board;
}

std::pair<int, int> Board::posChanging(int x, int y) {
    std::pair<int, int> ansPos = { 0, 0 };
    int a[8] = { 283, 360, 441, 521, 600, 759, 838, 917 };
    int b[10] = { 35, 118, 200, 282, 364, 447, 529, 611, 694, 775 };
    ansPos.first = x;
    ansPos.second = y;
    return ansPos;
}