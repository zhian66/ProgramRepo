#include "GameManager.h"

GameManager::GameManager() {
	current_player = 1;
	gameStatus = MENU;
}

void GameManager::menu() {
	viewer.printMenu();
	gameStatus = viewer.gameStatus;     // see what bottom you will click (StartBottom: 1, loadBottom: 2)
}

void GameManager::initGame() {
	current_player = 1;
	on_board = board.initBoard();
	viewer.chessStatus = WATING;
}

int GameManager::checkGameOver() {
	bool red_stalemate = true;				// ¤í¦æ§PÂ_
	bool black_stalemate = true;
	bool redKing = false;					// found king (king not exist -> lose)
	bool blackKing = false;
	bool black_checkmate = false;
	bool red_checkmate = false;

	std::vector<std::pair<int, int>> sugList;

	for (auto& chess : on_board) {
		if (chess->id == 1) {
			if (chess->color == 1)
				redKing = true;
			else if (chess->color == 2)
				blackKing = true;
		}
		sugList = chess->getSuggestion(board.board);
		for (auto& sug : sugList) {
			if (board.board[sug.first][sug.second]->id == 1) {
				if (chess->color == 1) {
					black_checkmate = true;
					break;
				} else {
					red_checkmate = true;
					break;
				}
			}
		}
		if (red_stalemate && sugList.size() != 0) {
			red_stalemate = false;
		} else if (black_stalemate && sugList.size() != 0) {
			black_stalemate = false;
		}
	}
	if (black_stalemate) return Red_Win;
	if (!redKing) return Black_Win;
	if (red_stalemate) return Black_Win;
	if (!blackKing) return Red_Win;
	if (black_checkmate) return Black_Checkmate;
	if (red_checkmate) return Red_Checkmate;
	return Continue;
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
					break;
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

		int check = checkGameOver();
		if (check) {
			enum GameOver {
				Continue, Red_Checkmate, Black_Checkmate, Red_Win, Black_Win
			};
			std::cout << "=================================================\n";
			std::cout << "check: " << check << "\n";


			if (check == Red_Checkmate)
				MessageBoxA(NULL, "Red Checkmate", "Warning", MB_OKCANCEL);
			else if (check == Black_Checkmate)
				MessageBoxA(NULL, "Black Checkmate", "Warning", MB_OKCANCEL);
			else if (check == Red_Win) {
				int result = MessageBoxA(NULL, "Red Win\nNew Game?", "Win", MB_YESNO);
				std::cout << result << "\n=============\n";
				if (result == IDYES) {
					gameStatus = NEW_GAME;
					viewer.chessStatus = GAME_OVER;
					return;
				} else if (result == IDNO) {
					gameStatus = MENU;
					viewer.chessStatus = GAME_OVER;
					return;
				}
			} else if (check == Black_Win) {
				int result = MessageBoxA(NULL, "Black Win\nNew Game?", "Win", MB_YESNO);
				std::cout << result << "\n=============\n";
				if (result == IDYES) {
					gameStatus = NEW_GAME;
					viewer.chessStatus = GAME_OVER;
					return;
				} else if (result == IDNO) {
					gameStatus = MENU;
					viewer.chessStatus = GAME_OVER;
					return;
				}
			}
		}
		current_player = current_player % 2 + 1;
	}
}


std::string GameManager::openFile() {

	char filename[MAX_PATH];
	char currFile[MAX_PATH];

	OPENFILENAMEA ofn = {0};
	
	ZeroMemory(&filename, sizeof(filename));	
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
	ofn.lpstrFilter = "All Files(*.*)\0*.*\0\0";
	ofn.lpstrFile = filename;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "Select a File, yo!";
	ofn.Flags = OFN_EXPLORER;
	ofn.lpstrCustomFilter = NULL;
	ofn.nFilterIndex = 0;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrInitialDir = NULL;
	//std::cout << GetOpenFileNameA(&ofn) << std::endl;
	//std::cout << filename << (int)CommDlgExtendedError();
	//GetCurrentDirectoryA(MAX_PATH, currFile);

	std::string path = "";

	if (GetOpenFileNameA((LPOPENFILENAMEA)&ofn)) {
		std::cout << "You chose the file \"" << ofn.lpstrFile << "\"\n";
		for (int i = 0; i < strlen(filename); i++) {
			if (filename[i] == '\\') {
				path += "\\\\";
			}
			else {
				path += filename[i];
			}
		}
		std::cout << path << "\n";
	}
	else {
		// All this stuff below is to tell you exactly how you messed up above.
		// Once you've got that fixed, you can often (not always!) reduce it to a 'user cancelled' assumption.
		switch (CommDlgExtendedError()) {
		case CDERR_DIALOGFAILURE:   std::cout << "CDERR_DIALOGFAILURE\n";    break;
		case CDERR_FINDRESFAILURE:  std::cout << "CDERR_FINDRESFAILURE\n";   break;
		case CDERR_INITIALIZATION:  std::cout << "CDERR_INITIALIZATION\n";   break;
		case CDERR_LOADRESFAILURE:  std::cout << "CDERR_LOADRESFAILURE\n";   break;
		case CDERR_LOADSTRFAILURE:  std::cout << "CDERR_LOADSTRFAILURE\n";   break;
		case CDERR_LOCKRESFAILURE:  std::cout << "CDERR_LOCKRESFAILURE\n";   break;
		case CDERR_MEMALLOCFAILURE: std::cout << "CDERR_MEMALLOCFAILURE\n";  break;
		case CDERR_MEMLOCKFAILURE:  std::cout << "CDERR_MEMLOCKFAILURE\n";   break;
		case CDERR_NOHINSTANCE:     std::cout << "CDERR_NOHINSTANCE\n";      break;
		case CDERR_NOHOOK:          std::cout << "CDERR_NOHOOK\n";           break;
		case CDERR_NOTEMPLATE:      std::cout << "CDERR_NOTEMPLATE\n";       break;
		case CDERR_STRUCTSIZE:      std::cout << "CDERR_STRUCTSIZE\n";       break;
		case FNERR_BUFFERTOOSMALL:  std::cout << "FNERR_BUFFERTOOSMALL\n";   break;
		case FNERR_INVALIDFILENAME: std::cout << "FNERR_INVALIDFILENAME\n";  break;
		case FNERR_SUBCLASSFAILURE: std::cout << "FNERR_SUBCLASSFAILURE\n";  break;
		default:                    std::cout << "You cancelled.\n";
		}
	}
	//SetCurrentDirectoryA(currFile);

	return path;
}

bool GameManager::LoadGame() {
	std::cout << "LoadGame\n";
	
	std::string filename, str, tmp;
	std::ifstream fp(openFile());
	std::stringstream check;
	std::vector<std::string> tokens;

	while (getline(fp, str)) {
		getline(check, tmp, ' ');
		tokens.push_back(tmp);
		//1 player, 3 Soldier (6, 6) -> (6, 5); 
		gameStatus = viewer.gameStatus;
		chessStatus = viewer.chessStatus;
		if (gameStatus == GAME_OVER) // surrender??
			break;
		if (chessStatus == KICK) {
			//what is kick?
		} else if (chessStatus == MOVE_PIECE) {
			//waiting to write
		}
	}
	fp.close();
	
	return false;
}



const bool GameManager::isRunning() const {
	return viewer.isRunning();
}

int GameManager::getStatus() const {
	return gameStatus;
}