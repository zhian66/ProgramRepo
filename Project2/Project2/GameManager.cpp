#include "GameManager.h"

GameManager::GameManager() {
	current_player = 1;
	gameStatus = MENU;
}

void GameManager::menu() {
	viewer.printMenu();
	gameStatus = viewer.gameStatus;     // see what bottom you will click (StartBottom: 1, ReadBottom: 2)
}

void GameManager::initGame() {
	current_player = 1;
	board.initBoard();
}

void GameManager::playGame() {
	while (gameStatus != GAME_OVER) {
		viewer.updateGame(board);
		gameStatus = viewer.gameStatus;
		chessStatus = viewer.chessStatus;
		if (gameStatus == GAME_OVER) // surrender??
			break;
		if (chessStatus == WATING) {
			// do nothing
		} else if (chessStatus == SHOW_SUGGEST) {
			std::vector<std::pair<int, int>> sugList;
			std::pair<int, int> pos = viewer.pressedPos;
			if (board.board[pos.first][pos.second]->id == 1) {
				sugList = board.board[pos.first][pos.second]->getSuggestion();
				for (auto& sug : sugList) {
					std::cout << sug.first << " " << sug.second << "\n";
				}
			}

		} else if (chessStatus == KICK) {

		} else if (chessStatus == MOVE_PIECE) {

		}
	}
}

bool GameManager::LoadGame() {
    return false;
}

const bool GameManager::isRunning() const {
	return viewer.isRunning();
}

int GameManager::getStatus() const {
	return gameStatus;
}