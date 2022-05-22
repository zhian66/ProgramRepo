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

int GameManager::checGameOver() {
	bool red_stalemate = true;				// 欠行判斷
	bool black_stalemate = true;
	bool redKing = false;					// found king (king not exist -> lose)
	bool blackKing = false;

	for (auto& chess : on_board) {
		if (chess->color == 1) {
			if (chess->id == 1) {
				redKing = true;
				for (int Y = chess->pos.second - 1; Y >= 0; Y--) {
					if (board.board[chess->pos.first][Y]->isActive) {
						if (board.board[chess->pos.first][Y]->id != 1)
							break;
						else return Black_Checkmate;
					}
				}
			}
			if (red_stalemate) {
				if ((chess->getSuggestion(board.board)).size() != 0) {
					red_stalemate = false;
				}
			}
		} else {
			if (chess->id == 1) {
				blackKing = true;
				for (int Y = chess->pos.second + 1; Y < 10; Y++) {
					if (board.board[chess->pos.first][Y]->isActive) {
						if (board.board[chess->pos.first][Y]->id != 1)
							break;
						else return Red_Checkmate;
					}
				}
			}
			if (black_stalemate) {
				if ((chess->getSuggestion(board.board)).size() != 0) {
					black_stalemate = false;
				}
			}
		}
	}
	if (black_stalemate) return Red_Win;
	if (!redKing) return Red_Win;
	if (red_stalemate) return Black_Win;
	if (!blackKing) return Black_Win;
	return false;
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
			Chess* temp = new Empty;
			for (auto it = on_board.begin(); it != on_board.end(); it++) {
				if (*it == board.board[pos.first][pos.second]) {
					on_board.erase(it);
				}
			}
			delete board.board[pos.first][pos.second];
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

		int check = checGameOver();
		if (check) {
			printMSG(check);
		}
		current_player = current_player % 2 + 1;
	}
}

void GameManager::printMSG(int check) {
	enum GameOver {
		Continue, Red_Checkmate, Black_Checkmate, Red_Win, Black_Win
	};
	std::cout << "check: " << check << "\n";
	/*
	if (check == Red_Checkmate)
		MessageBoxA(NULL, "紅方將軍", "注意", MB_OKCANCEL | MB_ICONEXCLAMATION);
	else if (check == Black_Checkmate)
		MessageBoxA(NULL, "黑方將軍", "注意", MB_OKCANCEL | MB_ICONEXCLAMATION);
	else if (check == Red_Win)
		MessageBoxA(NULL, "紅方獲勝\n是否開始新的一局?", "注意", MB_YESNO | MB_ICONEXCLAMATION);
	else if (check == Black_Win)
		MessageBoxA(NULL, "黑方獲勝\n是否開始新的一局?", "注意", MB_YESNO | MB_ICONEXCLAMATION);
	*/
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