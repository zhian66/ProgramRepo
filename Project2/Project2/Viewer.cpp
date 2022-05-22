#include "Viewer.h"

void setIcon(sf::RenderWindow& window) {
    sf::Image icon{};
    if (!icon.loadFromFile("Texture/icon.jpg")) {
        std::cout << "Set icon error\n";
    } else
        window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

std::pair<int, int> Board2Pixel(int x, int y) {   // Convert board x-y to windows x-y(pixel)
    int convertX = 265 + x * 76;
    int convertY = 5 + y * 80;
    return std::pair<int, int>{convertX, convertY};
}
 

bool Pixel2Board(int x, int y, std::pair<int, int>& pos) {     // Convert windows x-y(pixel) to board x-y
    if (x >= 940 || x < 265)
        return 0;
    if (y >= 790 || y < 5)
        return 0;
    pos.first = (x - 265) / 76;
    pos.second = (y - 5) / 80;
    return 1;
}

    
std::vector<sf::CircleShape> Viewer::SuggestCircle(const std::vector<std::pair<int, int>>& sugList) {
    std::vector<sf::CircleShape> cir;
    std::pair<int, int> pos;
    for (auto sug : sugList) {
        sf::CircleShape tmp(32.5);
        tmp.setFillColor(sf::Color(255, 120, 120, 200)); //rgb(248, 120, 120)
        pos = Board2Pixel(sug.first, sug.second);
        tmp.setPosition(pos.first, pos.second);
        cir.push_back(tmp);
    }
    return cir;
}


Viewer::Viewer() {
    sf::VideoMode videoMode(1200, 800);
    window = new sf::RenderWindow(videoMode, "ChineseChess");// Window's width size, Window's height size, titile
    setIcon(*window);
    gameStatus = 0; // Menu
    chessStatus = WATING;
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
    ReadButton.setTexture("LoadButton.png"); // Can Changing: Please save the Picture in Texture Folder
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
            gameStatus = NEW_GAME;
            break;
        }
        if (ReadButton.onClick(event)) {
            std::cout << "clicked read button\n";
            gameStatus = LOAD_GAME;
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

void Viewer::updateGame(const Board& board) {
    sf::Texture texture;
    sf::Sprite sprite;
    if (!texture.loadFromFile("Texture/ChessBoard.png", sf::IntRect(0, 0, 700, 785))) {
        std::cout << "Board Set Texture Faild\n";
    }
    sprite.setTexture(texture);
    sprite.setPosition(250, 0);

    std::vector<sf::Texture> chessTexture(32);
    std::vector<sf::Sprite> chessSprite(32);
    int i = 0;
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 10; y++) {
            if (!board.board[x][y]->isActive) continue;
            std::string path = "Texture/" + std::to_string(board.board[x][y]->color) + std::to_string(board.board[x][y]->id) + ".png";
            if (!chessTexture[i].loadFromFile(path, sf::IntRect(0, 0, 65, 65)))
                std::cout << "Chess Set Texture Faild\n";
            chessSprite[i].setTexture(chessTexture[i]);
            std::pair<int, int> pos = Board2Pixel(x, y);
            chessSprite[i].setPosition(pos.first, pos.second);
            i += 1;
        }
    }

    std::vector<sf::CircleShape> cir;
    
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            switch (event.type) {
            case sf::Event::Closed: // closing using the cross button of the window
                window->close(); // close the main window and gets out of this loop
                std::cout << "Close\n";
                gameStatus = GAME_OVER;
                break;
            case sf::Event::MouseButtonPressed: // clicking
                if (event.mouseButton.button == sf::Mouse::Right) {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                }
                break;
            }
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    std::pair<int, int> pos;

                    // if not click on board
                    if (!Pixel2Board(x, y, pos)) {                              
                        if (chessStatus == SHOW_SUGGEST) 
                            chessStatus = WATING;
                        continue;
                    } 

                    // click on board
                    std::cout << "Click " << board.board[pos.first][pos.second]->id << "\n";
                    pressedPos = pos;

                    // if not click on chess
                    if (!board.board[pos.first][pos.second]->isActive) { 
                        if (chessStatus == SHOW_SUGGEST) {
                            chessStatus = MOVE_PIECE;
                            return;
                        }
                        continue;
                    } 

                    //click on chess
                    if (chessStatus == WATING) {
                        chessStatus = SHOW_SUGGEST;
                        return;
                    } else if (chessStatus == SHOW_SUGGEST) {
                        chessStatus = KICK;
                        return;
                    }
                }
            }
            if (chessStatus == SHOW_SUGGEST) {
                cir = SuggestCircle(board.sugList);
                break;
            } 
        }

        window->clear(sf::Color::White);
        window->draw(sprite);
        for (auto c : chessSprite) {
            window->draw(c);
        }
        if (chessStatus == SHOW_SUGGEST) {
            for (auto sug : cir) {
                window->draw(sug);
            }
        }
        window->display();
    }
}



const bool Viewer::isRunning() const {
    return window->isOpen();
}

