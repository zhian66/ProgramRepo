#pragma oncef
#include <vector>
#include "Viewer.h"
#include "Board.h"

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

}; 