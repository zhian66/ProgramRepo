#pragma once
#include <vector>
#include "Viewer.h"
#include "Board.h"

class GameManager {
	enum GameStatus { MENU, NEW_GAME, LOAD_GAME };
	enum ChessStatus { WATING, SHOW_SUGGEST, MOVE_PIECE };
	std::vector<Chess> on_board;
	int current_player; // 1: Player1, 2: Player2
	Board board;
	Viewer viewer;
	int gameStatus;		// 0: menu, 1: new_game, 2: load_game
	int chessStatus;	// 0:wating click, 1: show suggestion, 2: move piece

public:
	GameManager();
	void menu();
	void initGame();    // initialize game
	bool LoadGame();    // load game
	void playGame();    // play initialized/loaded game

	const bool isRunning() const;
	int getStatus() const;

}; 
