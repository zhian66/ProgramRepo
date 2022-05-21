#pragma once
#include <vector>
#include "Viewer.h"
#include "Board.h"

class GameManager {
	std::vector<Chess> on_board;
	int current_player; // 1: Player1, 2: Player2
	Board board;
	Viewer viewer;
	int currStatus;


public:
	GameManager();
	void menu();
	void initGame();
	bool LoadGame();
	void playGame();

	const bool isRunning() const;
	int getStatus() const;

};