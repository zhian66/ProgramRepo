#include "Viewer.h"

void setIcon(sf::RenderWindow& window) {
    sf::Image icon{};
    if (!icon.loadFromFile("Texture/icon.jpg")) {
        std::cout << "Set icon error\n";
    } else
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

Viewer::Viewer() {
    sf::VideoMode videoMode(1200, 800);
    window = new sf::RenderWindow(videoMode, "ChineseChess");// Window's width size, Window's height size, titile
    setIcon(*window);
    currStatus = 0; // Menu
}

Viewer::~Viewer() {
    delete window;
}

void Viewer::printMenu() {
    std::cout << "Viewer::PrintMenu\n";
    Button startButton;
    startButton.app = window;
    startButton.setTexture("StartButton.png"); // Can Changing: Please save the Picture in Texture Folder
    startButton.setPosition(500, 400, 200, 80); // start x, start y, width, height 

    Button ReadButton;
    ReadButton.app = window;
    ReadButton.setTexture("ReadButton.png"); // Can Changing: Please save the Picture in Texture Folder
    ReadButton.setPosition(500, 510, 200, 80);  // start x, start y, width, height 

    Button EndButton;
    EndButton.app = window;
    EndButton.setTexture("EndButton.png"); // Can Changing: Please save the Picture in Texture Folder
    EndButton.setPosition(500, 620, 200, 80);  // start x, start y, width, height 

    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed: // closing using the cross button of the window
                window->close(); // close the main window and gets out of this loop
                std::cout << "Close\n";
                break;
            case sf::Event::LostFocus:
                std::cout << "LostFoucus\n";
                break;
            case sf::Event::MouseButtonPressed: // clicking
                if (event.mouseButton.button == sf::Mouse::Right) {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
                break;
            default:
                break;
            }
        }
        if (startButton.onClick(event)) {
            std::cout << "clicked start button\n";
            currStatus = 1;
            break;
        }
        if (ReadButton.onClick(event)) {
            std::cout << "clicked read button\n";
            currStatus = 2;
            break;
        }
        if (EndButton.onClick(event)) {
            std::cout << "clicked end button\n";
            window->close();
        }

        window->clear(sf::Color::White);
        ReadButton.show();
        EndButton.show();
        startButton.show();
        window->display();
    }
}

void Viewer::updateGame(Board& board) {
    sf::Texture texture;
    sf::Sprite sprite;
    if (!texture.loadFromFile("Texture/ChessBoard.png", sf::IntRect(0, 0, 700, 800))) {
        std::cout << "Board Set Texture Faild\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(250, 0);

    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed: // closing using the cross button of the window
                window->close(); // close the main window and gets out of this loop
                std::cout << "Close\n";
                break;
            case sf::Event::MouseButtonPressed: // clicking
                if (event.mouseButton.button == sf::Mouse::Right) {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
                if (event.mouseButton.button == sf::Mouse::Left) {
                    for (int i = 0; i < 10; i++) {
                        for (int j = 0; j < 9; j++) {
                            if 
                        }
                    }
                }
                break;
            }

        }

        window->clear(sf::Color::White);
        window->draw(sprite);
        window->display();
    }
}

const bool Viewer::isRunning() const {
    return window->isOpen();
}