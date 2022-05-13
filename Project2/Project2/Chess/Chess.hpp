//
//  Chess.hpp
//  Chinese_Chess
//
//  Created by RinKawano on 2022/5/12.
//

#ifndef Chess_hpp
#define Chess_hpp


typedef struct pair{
    int x = 0;
    int y = 0;
} pair;


class Chess {
public:
    pair position;
    Chess();
    Chess(const Chess& piece);                                  // copy constructor
    Chess(const int& X, const int& Y);                          // construct by setting position
    Chess(const pair& pos);                                     // construct by setting position using type: pair
    ~Chess();
    Chess& operator= (const Chess& piece);                      // assign a class
    Chess& operator= (const pair& pos);                         // assign the position to the Chess
    virtual void getSuggestion() = 0;                              // get suggestion where you can go
    void go(const int& X, const int& Y);                        // go to the position
    void go(const pair& pos);                                   // go to the position
    void stay();                                                // do not move
    void kick();                                                // kick the opponent
};


#endif /* Chess_hpp */
