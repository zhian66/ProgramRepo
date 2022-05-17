#include <iostream>
#include <string>
#include "Button.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Chinese Chess"); // Window's width size, Window's height size, titile
    //window.clear(sf::Color{ 217, 207, 148, 1 }); // without checking

    Button startButton;
    startButton.app = &window;
    startButton.setTexture("StartButton.png"); // Can Changing: Please save the Picture in Texture Folder
    // startButton.setText("Start Game"); // Not Working
    startButton.setPosition(500, 400, 200, 80); // start x, start y, width, height 

    Button ReadButton;
    ReadButton.app = &window;
    ReadButton.setTexture("ReadButton.png"); // Can Changing: Please save the Picture in Texture Folder
    // ReadButton.setText("Read Game"); // Not Working
    ReadButton.setPosition(500, 510, 200, 80);  // start x, start y, width, height 

    Button EndButton;
    EndButton.app = &window;
    EndButton.setTexture("EndButton.png"); // Can Changing: Please save the Picture in Texture Folder
    //EndButton.setText("End Game"); // Not Working
    EndButton.setPosition(500, 620, 200, 80);  // start x, start y, width, height 


    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed: // closing using the cross button of the window
                window.close(); // close the main window and gets out of this loop
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
            
        }
        if (ReadButton.onClick(event)) {
            std::cout << "clicked read button\n";

        }
        if (EndButton.onClick(event)) {
            std::cout << "clicked end button\n";
            window.close();
        }

        window.clear();
        startButton.setActive(false);
        startButton.show();
        ReadButton.show();
        EndButton.show();
        //window.draw(text);
        window.display();
        
    }

    return 0;
}

