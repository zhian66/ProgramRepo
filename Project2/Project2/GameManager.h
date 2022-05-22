#pragma comment(lib,"User32.lib")
/*
#define WIN32_LEAN_AND_MEAN
#include "SFML/Window.hpp"
*/

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <Commdlg.h>
#include <winbase.h>

#include <vector>
#include "Viewer.h"
#include "Board.h"

#include <iostream>
#include <string>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <sstream>




class GameManager {
	enum GameStatus { MENU, NEW_GAME, LOAD_GAME, GAME_OVER};
	enum ChessStatus { WATING, SHOW_SUGGEST, KICK, MOVE_PIECE };
	std::vector<Chess*> on_board;
	int current_player; // 1: Player1, 2: Player2
	Board board;
	Viewer viewer;
	int gameStatus;		// 0: menu, 1: new_game, 2: load_game, 3: gaem_over
	int chessStatus;	// 0:wating click, 1: show suggestion, 2: kick, 3: move piece
    std::ofstream save_data;

	enum GameOver {
		Continue, Red_Checkmate, Black_Checkmate, Red_Win, Black_Win
	};
	int checkGameOver();	// return 0: false, 1: RED_checkmate 2: Black_checkmate, 3: Red_win 4: Black_win

public:
	GameManager();
	void menu();
	void initGame();    // initialize game
	bool LoadGame();    // load game
	void playGame();    // play initialized/loaded game

	const bool isRunning() const;
	int getStatus() const;
	std::string openFile();

}; 
