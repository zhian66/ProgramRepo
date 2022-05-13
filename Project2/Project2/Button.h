#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class Button {
protected:
    std::string ButtonName;
    sf::Texture texture;
    sf::Text text;
    sf::String str;
    int px, py;
    bool isActive;
    bool isPressed;
public:
    sf::RenderWindow* app;
    sf::Sprite button;

    Button() : ButtonName("Button"), app(NULL), isActive(false), isPressed(false) {};
    Button(std::string name) : ButtonName(name), app(NULL), isActive(false), isPressed(false) {};
    void setTexture(sf::String s);
    void setPosition(int px, int py, int sx, int sy);
    void setText(sf::String str, float size = 24, sf::String Fontpath = "");
    void setActive(bool flag);
    void setPressedStatus(bool flag);
    void show();
    bool onClick(sf::Event& e);

};

