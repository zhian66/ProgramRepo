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
	on_board = board.initBoard();
}

void GameManager::playGame() {
	std::pair<int, int> pos(-1, -1);
	std::pair<int, int> prePos;

	while (gameStatus != GAME_OVER) {
		viewer.updateGame(board);

		gameStatus = viewer.gameStatus;

		prePos = pos;
		pos = viewer.pressedPos;


		if (gameStatus == GAME_OVER) // surrender??
			break;

		if (viewer.chessStatus == WATING) {
			// do nothing
		} 
		
		// check if move in suggestion list
		bool found = false;
		for (auto& sug : board.sugList) {
			if (pos == sug) {
				found = true;
				break;
			}
		}
		if (!found) 
			viewer.chessStatus = SHOW_SUGGEST;

		if (viewer.chessStatus == SHOW_SUGGEST) {
			// If Wrong Player click
			if (board.board[pos.first][pos.second]->color != current_player) {
				viewer.chessStatus = WATING;
				continue;
			} 
			board.sugList = board.board[pos.first][pos.second]->getSuggestion(board.board);
			std::cout << "Show Suggestion\n";
			for (auto& sug : board.sugList) {
				std::cout << sug.first << " " << sug.second << "\n";
			}
			continue;
		}

		if (viewer.chessStatus == KICK) {
			std::cout << "Kick\n";
			delete board.board[pos.first][pos.second];
			Chess* temp = new Empty;
			board.board[pos.first][pos.second] = board.board[prePos.first][prePos.second];
			board.board[prePos.first][prePos.second] = temp;
			board.board[pos.first][pos.second]->pos.first = pos.first;
			board.board[pos.first][pos.second]->pos.second = pos.second;
			viewer.chessStatus = WATING;

		} else if (viewer.chessStatus == MOVE_PIECE) {
			std::cout << "Move piece\n";
			delete board.board[pos.first][pos.second];
			Chess* temp = new Empty;
			board.board[pos.first][pos.second] = board.board[prePos.first][prePos.second];
			board.board[prePos.first][prePos.second] = temp;
			board.board[pos.first][pos.second]->pos.first = pos.first;
			board.board[pos.first][pos.second]->pos.second = pos.second;
			viewer.chessStatus = WATING;
		}
		current_player = current_player % 2 + 1;
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