#include "Button.h"

void Button::setTexture(sf::String s) {

    if (!texture.loadFromFile("Texture/" + s, sf::IntRect(0, 0, 200, 100))) {
        std::cout << ButtonName << " Set Texture Faild\n";
        return;
    }
    button.setTexture(texture);
}

void Button::setPosition(int px, int py, int sx, int sy) {
    this->px = px;
    this->py = py;
    button.setPosition(px, py);
}

void Button::setText(sf::String str, float size, sf::String Fontpath) {
    sf::Font font;
    if (Fontpath == "") {
        Fontpath = "Font/calibri.ttf";
    }
    font.loadFromFile(Fontpath);
    text.setFont(font);

    text.setString(str);
    text.setCharacterSize(size);
    text.setFillColor(sf::Color::Yellow);
    text.setStyle(sf::Text::Bold);
    text.setPosition(0, 0);

}

void Button::setActive(bool flag) {
    isActive = flag;
}

void Button::setPressedStatus(bool flag) {
    isPressed = flag;
}

void Button::show() {
    isActive = true;
    //(*app).draw(text);
    (*app).draw(button);

}

bool Button::onClick(sf::Event& e) {
    if (!isActive)
        return false;
    bool flag = false;
    sf::FloatRect box = button.getGlobalBounds(); // get button vaild click scope. 
    if (sf::Mouse::getPosition(*app).x >= box.left && sf::Mouse::getPosition(*app).x <= (box.left + box.width)) {
        if (sf::Mouse::getPosition(*app).y >= box.top && sf::Mouse::getPosition(*app).y <= (box.top + box.height)) {
            if (e.type == sf::Event::MouseButtonReleased && e.key.code == sf::Mouse::Left && isPressed) {
                isPressed = false; // Button must be pressed and released than return true
                flag = true;
            }
            else
                flag = false;

            if (e.type == sf::Event::MouseButtonPressed && e.key.code == sf::Mouse::Left) {
                button.setColor(sf::Color(125, 125, 100, 100)); // Set color of the pressed button
                isPressed = true;
            }
            else
                button.setColor(sf::Color(125, 125, 125, 255)); // Set button being pointed yet pressed

        }
    }
    else
        button.setColor(sf::Color(255, 255, 255, 255)); // Set color of the origin button

    return flag;
}

/*
void midTextvoid(sf::Vector2f pos) {
    button.setPosition(pos);

    float pos_x = (pos.x + button.getGlobalBounds().width / 3.0f) -
        (text.getGlobalBounds().width / 2);
    float pos_y = (pos.y + button.getGlobalBounds().height / 3.0f) -
        (text.getGlobalBounds().height / 2);
    text.setPosition(pos_x, pos_y);
}*/