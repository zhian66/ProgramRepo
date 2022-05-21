#include "GameManager.h"

GameManager::GameManager() {
	current_player = 1;
    currStatus = 0;
}

void GameManager::menu() {
	viewer.printMenu();
	currStatus = viewer.currStatus;     // see what bottom you will click (StartBottom: 1, ReadBottom: 2)
}

void GameManager::initGame() {
	current_player = 1;
}

void GameManager::playGame() {
	viewer.updateGame();
	currStatus = viewer.currStatus;
}

bool GameManager::LoadGame() {
    
}

const bool GameManager::isRunning() const {
	return viewer.isRunning();
}

int GameManager::getStatus() const {
	return currStatus;
}
