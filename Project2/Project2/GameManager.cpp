#include "GameManager.h"

GameManager::GameManager() {
	current_player = 1;
}

void GameManager::menu() {
	viewer.printMenu();
	currStatus = viewer.currStatus;
}

void GameManager::initGame() {
	current_player = 1;
}

void GameManager::playGame() {
	viewer.updateGame();
	currStatus = viewer.currStatus;

}




const bool GameManager::isRunning() const {
	return viewer.isRunning();
}

int GameManager::getStatus() const {
	return currStatus;
}
