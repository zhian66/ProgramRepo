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

std::vector<Chess*> Board::initBoard() {
    board.resize(10);
    for (int i = 0; i < 10; i++)
        board[i].resize(10);
    std::vector<Chess*> on_board;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            // color 0 is black, 1 is red
            int color = i < 5 ? 2 : 1;
            if (nameTable[i][j] == "Empty") {
                board[j][i] = new Empty();
                continue;
            } else if (nameTable[i][j] == "King") {
                board[j][i] = new King(j, i, color);
            } else if (nameTable[i][j] == "Guard") {
                board[j][i] = new Guard(j, i, color);
            } else if (nameTable[i][j] == "Minister") {
                board[j][i] = new Minister(j, i, color);
            } else if (nameTable[i][j] == "Horse") {
                board[j][i] = new Horse(j, i, color);
            } else if (nameTable[i][j] == "Rook") {
                board[j][i] = new Rook(j, i, color);
            } else if (nameTable[i][j] == "Cannon") {
                board[j][i] = new Cannon(j, i, color);
            } else if (nameTable[i][j] == "Pawn") {
                board[j][i] = new Pawn(j, i, color);
            }
            on_board.push_back(board[j][i]);
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