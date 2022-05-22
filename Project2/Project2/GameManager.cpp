#include "GameManager.h"

void initBoard() {
	
}


void GameManager::initGame() {
<<<<<<< Updated upstream
	
=======
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

<<<<<<< Updated upstream
std::string GameManager::openFile() {
    char filename[MAX_PATH];

    OPENFILENAMEA ofn;
    ZeroMemory(&filename, sizeof(filename));
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
    ofn.lpstrFilter = "All Files(*.*)\0*.*\0\0";
    ofn.lpstrFile = filename;
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrTitle = "Select a File, yo!";
    ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

    if (GetOpenFileNameA((LPOPENFILENAMEA)&ofn)) {
        std::cout << "You chose the file \"" << ofn.lpstrFile << "\"\n";
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
    return std::string(ofn.lpstrFile);
=======
void GameManager::printMSG(int check) {
	enum GameOver {
		Continue, Red_Checkmate, Black_Checkmate, Red_Win, Black_Win
	};
	std::cout << "=================================================\n";
	std::cout << "check: " << check << "\n";
	/*
	if (check == Red_Checkmate)
		MessageBoxA(NULL, "Red Checkmate", "Warning", MB_OKCANCEL);
	else if (check == Black_Checkmate)
		MessageBoxA(NULL, "Black Checkmate", "Warning", MB_OKCANCEL);
	else if (check == Red_Win)
		MessageBoxA(NULL, "Red Win", "Warning", MB_YESNO);
	else if (check == Black_Win)
		MessageBoxA(NULL, "Black Win", "Warning", MB_YESNO | MB_ICONEXCLAMATION);
	*/
	
}

std::string GameManager::openFile() {
	char filename[MAX_PATH];

	OPENFILENAMEA ofn;
	ZeroMemory(&filename, sizeof(filename));
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
	ofn.lpstrFilter = "All Files(*.*)\0*.*\0\0";
	ofn.lpstrFile = filename;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = "Select a File, yo!";
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

	GetOpenFileNameA((LPOPENFILENAMEA)&ofn);

	/*
	if (GetOpenFileNameA((LPOPENFILENAMEA)&ofn)) {
		std::cout << "You chose the file \"" << ofn.lpstrFile << "\"\n";
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
	}*/
	return std::string(ofn.lpstrFile);
>>>>>>> Stashed changes
}

bool GameManager::LoadGame() {

    std::string filename, str, tmp;
    std::ifstream fp(openFile());
    std::stringstream check;
    std::vector<std::string> tokens;

    while (getline(fp, str)) {
        getline(check, tmp, ' ');
        tokens.push_back(tmp);
        //1 player, 3 Soldier (6, 6) -> (6, 5); 
        viewer.updateGame(board);
        gameStatus = viewer.gameStatus;
        chessStatus = viewer.chessStatus;
        if (gameStatus == GAME_OVER) // surrender??
            break;
        if (chessStatus == KICK) {
            //what is kick?
        }
        else if (chessStatus == MOVE_PIECE) {
            //waiting to write
        }
    }
        return false;//why return false?
}

const bool GameManager::isRunning() const {
	return viewer.isRunning();
}

int GameManager::getStatus() const {
	return gameStatus;
>>>>>>> Stashed changes
}