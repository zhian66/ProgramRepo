#include "Board.h"

Board::Board() {
    King King1(4, 9, 0), King2(4, 0, 1);
    Guard Guard1_1(3, 9, 0), Guard1_2(5, 9, 0), Guard2_1(3, 0, 1), Guard2_2(5, 0, 1);
    Minister Minister1_1(2, 9, 0), Minister1_2(6, 9, 0), Minister2_1(2, 0, 1), Minister2_2(6, 0, 1);
    Rook Rook1_1(0, 9, 0), Rook1_2(8, 9, 0), Rook2_1(0, 0, 1), Rook2_2(8, 0, 1);
    Horse Horse1_1(1, 9, 0), Horse1_2(7, 9, 0), Horse2_1(1, 0, 1), Horse2_2(7, 0, 1);
    Cannon Cannon1_1(1, 7, 0), Cannon1_2(7, 7, 0), Cannon2_1(1, 2, 1), Cannon2_2(7, 2, 1);
    Pawn Pawn1_1(0, 6, 0), Pawn1_2(2, 6, 0), Pawn1_3(4, 6, 0), Pawn1_4(6, 6, 0), Pawn1_5(8, 6, 0);
    Pawn Pawn2_1(0, 3, 1), Pawn2_2(2, 3, 1), Pawn2_3(4, 3, 1), Pawn2_4(6, 3, 1), Pawn2_5(8, 3, 1);
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

std::pair<int, int> Board::posChanging(std::pair<int, int> pos) {
	std::pair<int, int> ansPos = { 0, 0 };
	int a[8] = { 283, 360, 441, 521, 600, 759, 838, 917 };
	int b[10] = { 35, 118, 200, 282, 364, 447, 529, 611, 694, 775 };
	ansPos.first = a[pos.first];
	ansPos.second = b[pos.second];
	return ansPos;
}