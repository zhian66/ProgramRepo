#pragma once
#include <iostream>
#include "Button.h"
#include <utility>
#include "Board.h"
#include "SFML/Graphics.hpp"

class Viewer {
public:
	Viewer();
	~Viewer();
	int gameStatus;		// 0: Menu, 1: NewGame, 2: LoadGame
	int chessStatus;	// 0:wating click, 1: show suggestion, 2: kick, 3: move piece
	std::pair<int, int> pressedPos;


	void printMenu();
	void updateGame(const Board& board);
	const bool isRunning() const;

private:
	enum GameStatus { MENU, NEW_GAME, LOAD_GAME };
	enum ChessStatus { WATING, SHOW_SUGGEST, KICK, MOVE_PIECE };

	friend void setIcon(sf::RenderWindow& window);
	sf::RenderWindow* window;
	sf::Event event;

};