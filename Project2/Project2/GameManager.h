#pragma oncef
#include <vector>
#include "Viewer.h"
#include "Board.h"

#include <iostream>
#include <windows.h>
#include <string>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <sstream>

class GameManager {
	//std::vector<Chess> on_board;
	int current_player;
	Board board;
	Viewer viewer;

public:
	GameManager();
	void initGame();
	bool LoadGame();
	void playGame();

<<<<<<< Updated upstream
}; 
=======
	const bool isRunning() const;
	int getStatus() const;

	std::string openFile();
}; 
>>>>>>> Stashed changes
