#pragma once
#include <iostream>
#include "Button.h"
#include ".\SFML-2.5.1\include\SFML\Graphics.hpp"

class Viewer {
public:
	Viewer();
	void printMenu();
	const bool isRunning() const;

private:
	friend void setIcon(sf::RenderWindow& window);
	sf::RenderWindow *window;
	sf::Event event;
	
};