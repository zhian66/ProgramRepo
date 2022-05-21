//  Created by RinKawano
#include <iostream>
#include <vector>

#ifndef Chess_h
#define Chess_h

class Chess {
public:
    std::pair<int, int> pos;
    Chess();
    Chess(const Chess& piece);                                  // copy constructor
    Chess(const int& X, const int& Y);                          // construct by setting position
    Chess(const std::pair<int, int>& Pos);                      // construct by setting position using type: pair
    ~Chess();
    Chess& operator= (const Chess& piece);                      // assign a class
    Chess& operator= (const std::pair<int, int>& pos);          // assign the position to the Chess
    virtual std::vector<std::pair<int, int>>& getSuggestion();  // get suggestion where you can go
    void go(const int& X, const int& Y);                        // go to the position
    void go(const std::pair<int, int>& pos);                    // go to the position
    void stay();                                                // do not move
    void kick();                                                // kick the opponent
};

class King : public Chess {
public:
    King();
    King(const King& king);
    King(const int& X, const int& Y);
    King(const std::pair<int, int>& Pos);
    ~King();
    King& operator= (const King& king);
    King& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>>& getSuggestion() override;
};

class Pawn : public Chess {
public:
    Pawn();
    Pawn(const Pawn& pawn);
    Pawn(const int& X, const int& Y);
    Pawn(const std::pair<int, int>& Pos);
    ~Pawn();
    Pawn& operator= (const Pawn& pawn);
    Pawn& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>>& getSuggestion() override;
};

class Rook : public Chess {
public:
    Rook();
    Rook(const Rook& rook);
    Rook(const int& X, const int& Y);
    Rook(const std::pair<int, int>& Pos);
    ~Rook();
    Rook& operator= (const Rook& rook);
    Rook& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>>& getSuggestion() override;
};

class Minister : public Chess {
public:
    Minister();
    Minister(const Minister& minister);
    Minister(const int& X, const int& Y);
    Minister(const std::pair<int, int>& Pos);
    ~Minister();
    Minister& operator= (const Minister& minister);
    Minister& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>>& getSuggestion() override;
};

class Horse : public Chess {
public:
    Horse();
    Horse(const Horse& horse);
    Horse(const int& X, const int& Y);
    Horse(const std::pair<int, int>& Pos);
    ~Horse();
    Horse& operator= (const Horse& horse);
    Horse& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>>& getSuggestion() override;
};

class Cannon : public Chess {
public:
    Cannon();
    Cannon(const Cannon& cannon);
    Cannon(const int& X, const int& Y);
    Cannon(const std::pair<int, int>& Pos);
    ~Cannon();
    Cannon& operator= (const Cannon& cannon);
    Cannon& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>>& getSuggestion() override;
};

class Guard : public Chess {
public:
    Guard();
    Guard(const Guard& guard);
    Guard(const int& X, const int& Y);
    Guard(const std::pair<int, int>& Pos);
    ~Guard();
    Guard& operator= (const Guard& guard);
    Guard& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>>& getSuggestion() override;
};


#endif  /*  Chess_h  */
