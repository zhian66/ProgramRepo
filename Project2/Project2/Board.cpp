//  Created by RinKawano

#include "Board.h"

Board::Board() {
    King King1(4, 9), King2(4, 0);
    Guard Guard1_1(3, 9), Guard1_2(5, 9), Guard2_1(3, 0), Guard2_2(5, 0);
    Minister Minister1_1(2, 9), Minister1_2(6, 9), Minister2_1(2, 0), Minister2_2(6, 0);
    Rook Rook1_1(0, 9), Rook1_2(8, 9), Rook2_1(0, 0), Rook2_2(8, 0);
    Horse Horse1_1(1, 9), Horse1_2(7, 9), Horse2_1(1, 0), Horse2_2(7, 0);
    Cannon Cannon1_1(1, 7), Cannon1_2(7, 7), Cannon2_1(1, 2), Cannon2_2(7, 2);
    Pawn Pawn1_1(0, 6), Pawn1_2(2, 6), Pawn1_3(4, 6), Pawn1_4(6, 6), Pawn1_5(8, 6);
    Pawn Pawn2_1(0, 3), Pawn2_2(2, 3), Pawn2_3(4, 3), Pawn2_4(6, 3), Pawn2_5(8, 3);
}

Board::Board(const Board& brd) {
    board = brd;
}

Board::~Board() {
    
}

Board& Board::operator= (const Board& brd) {
    board = brd;
    return *this;
}

