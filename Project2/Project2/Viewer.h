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
	int gameStatus;		// 0: menu, 1: new_game, 2: load_game, 3: gaem_over
	int chessStatus;	// 0:wating click, 1: show suggestion, 2: kick, 3: move piece
	std::pair<int, int> pressedPos;


	void printMenu();
	void updateGame(const Board& board);
	const bool isRunning() const;

private:
	enum GameStatus { MENU, NEW_GAME, LOAD_GAME, GAME_OVER };
	enum ChessStatus { WATING, SHOW_SUGGEST, KICK, MOVE_PIECE };

	friend void setIcon(sf::RenderWindow& window);
	sf::RenderWindow* window;
	sf::Event event;

};