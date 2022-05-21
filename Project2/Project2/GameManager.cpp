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
	board.initBoard();
}

void GameManager::playGame() {
	viewer.updateGame(board);
	gameStatus = viewer.gameStatus;
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