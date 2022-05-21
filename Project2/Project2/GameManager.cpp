#include "GameManager.h"

GameManager::GameManager() {
	current_player = 1;
	gameStatus = 0;
}

void GameManager::menu() {
	viewer.printMenu();
	gameStatus = viewer.currStatus;     // see what bottom you will click (StartBottom: 1, ReadBottom: 2)
}

void GameManager::initGame() {
	current_player = 1;
	board.initBoard();
}

void GameManager::playGame() {
	viewer.updateGame(board);
	gameStatus = viewer.currStatus;
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