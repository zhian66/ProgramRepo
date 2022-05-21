#pragma once
#include <vector>
#include "Viewer.h"
#include "Board.h"

class GameManager {
	std::vector<Chess> on_board;
	int current_player; // 1: Player1, 2: Player2
	Board board;
	Viewer viewer;
	int gameStatus;		// 0: menu, 1: new_game, 2: load_game
	int chessStatus;	

public:
	GameManager();
	void menu();
	void initGame();    // initialize game
	bool LoadGame();    // load game
	void playGame();    // play initialized/loaded game

	const bool isRunning() const;
	int getStatus() const;

}; 
