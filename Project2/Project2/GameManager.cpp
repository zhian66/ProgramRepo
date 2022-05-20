#include "GameManager.h"

GameManager::GameManager() {
	//viewer.initViewer();
	current_player = 1;
	viewer.printMenu();
}

void GameManager::menu() {
	viewer.printMenu();
}

void GameManager::initGame() {
	
}

void initBoard() {

}

bool GameManager::LoadGame() {
    
}

void GameManager::playGame() {
    
}

const bool GameManager::isRunning() const {
	return viewer.isRunning();
}
