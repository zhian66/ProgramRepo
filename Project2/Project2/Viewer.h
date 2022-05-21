#pragma once
#include <iostream>
#include "Button.h"
#include "Board.h"
#include "SFML/Graphics.hpp"

class Viewer {
public:
	Viewer();
	~Viewer();
	int currStatus;		// 0: Menu, 1: NewGame, 2: LoadGame

	void printMenu();
	void updateGame(Board& board);
	const bool isRunning() const;

private:
	friend void setIcon(sf::RenderWindow& window);
	sf::RenderWindow* window;
	sf::Event event;
};