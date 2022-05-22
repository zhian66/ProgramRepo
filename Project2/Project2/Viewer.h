#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include <utility>
#include "Button.h"
#include "Board.h"

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

	std::vector<sf::CircleShape> SuggestCircle(const std::vector<std::pair<int, int>>& sugList);
	friend void setIcon(sf::RenderWindow& window);

	sf::RenderWindow* window;
	sf::Event event;

};