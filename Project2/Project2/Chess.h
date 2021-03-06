//  Created by RinKawano
#include <iostream>
#include <vector>

#ifndef Chess_h
#define Chess_h

class Chess {
public:
    std::pair<int, int> pos;                                    // default is (0, 0)
    int color;                                                  // 1:Red or 2:Black 3: none
    bool isActive;                                              // default is false
    int id;                                                     // Numbering of chess, 
                                                                // 1:king(將), 2:Guard(士), 3:Minister(相), 4:Horse(馬)
                                                                // 5:Rook(車), 6:Cannon(炮), 7:Pawn(兵)
    Chess();
    Chess(const Chess& piece);                                  // copy constructor
    Chess(const int& X, const int& Y);                          // construct by setting position
    Chess(const std::pair<int, int>& Pos);                      // construct by setting position using type: pair
    Chess(const int& X, const int& Y, int color);               // construct by setting position, set color
    ~Chess();
    Chess& operator= (const Chess& piece);                      // assign a class
    Chess& operator= (const std::pair<int, int>& pos);          // assign the position to the Chess

    bool operator==(const Chess& piece);

    virtual std::vector<std::pair<int, int>> getSuggestion(std::vector<std::vector<Chess*>> board);
    // get suggestion where you can go
    
    void go(const int& X, const int& Y);                        // go to the position
    void go(const std::pair<int, int>& pos);                    // go to the position
    void stay();                                                // do not move
    void kick();                                                // kick the opponent
    bool inEnemy();                                             // if you are in the enemy area
};

class King : public Chess {
public:
    King();
    King(const King& king);
    King(const int& X, const int& Y);
    King(const std::pair<int, int>& Pos);
    King(const int& X, const int& Y, int color);
    ~King();
    King& operator= (const King& king);
    King& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>> getSuggestion(std::vector<std::vector<Chess*>> board) override;
};

class Pawn : public Chess {
public:
    Pawn();
    Pawn(const Pawn& pawn);
    Pawn(const int& X, const int& Y);
    Pawn(const std::pair<int, int>& Pos);
    Pawn(const int& X, const int& Y, int color);  
    ~Pawn();
    Pawn& operator= (const Pawn& pawn);
    Pawn& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>> getSuggestion(std::vector<std::vector<Chess*>> board) override;
};

class Rook : public Chess {
public:
    Rook();
    Rook(const Rook& rook);
    Rook(const int& X, const int& Y);
    Rook(const std::pair<int, int>& Pos);
    Rook(const int& X, const int& Y, int color);
    ~Rook();
    Rook& operator= (const Rook& rook);
    Rook& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>> getSuggestion(std::vector<std::vector<Chess*>> board) override;
};

class Minister : public Chess {
public:
    Minister();
    Minister(const Minister& minister);
    Minister(const int& X, const int& Y);
    Minister(const std::pair<int, int>& Pos);
    Minister(const int& X, const int& Y, int color);
    ~Minister();
    Minister& operator= (const Minister& minister);
    Minister& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>> getSuggestion(std::vector<std::vector<Chess*>> board) override;
};

class Horse : public Chess {
public:
    Horse();
    Horse(const Horse& horse);
    Horse(const int& X, const int& Y);
    Horse(const std::pair<int, int>& Pos);
    Horse(const int& X, const int& Y, int color);
    ~Horse();
    Horse& operator= (const Horse& horse);
    Horse& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>> getSuggestion(std::vector<std::vector<Chess*>> board) override;
};

class Cannon : public Chess {
public:
    Cannon();
    Cannon(const Cannon& cannon);
    Cannon(const int& X, const int& Y);
    Cannon(const std::pair<int, int>& Pos);
    Cannon(const int& X, const int& Y, int color);
    ~Cannon();
    Cannon& operator= (const Cannon& cannon);
    Cannon& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>> getSuggestion(std::vector<std::vector<Chess*>> board) override;
};

class Guard : public Chess {
public:
    Guard();
    Guard(const Guard& guard);
    Guard(const int& X, const int& Y);
    Guard(const std::pair<int, int>& Pos);
    Guard(const int& X, const int& Y, int color);
    ~Guard();
    Guard& operator= (const Guard& guard);
    Guard& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>> getSuggestion(std::vector<std::vector<Chess*>> board) override;
};

class Empty : public Chess {
public:
    Empty();
    Empty& operator= (const Empty& empty);
    Empty& operator= (const std::pair<int, int>& Pos);
    std::vector<std::pair<int, int>> getSuggestion(std::vector<std::vector<Chess*>> board) override;
};


#endif  /*  Chess_h  */
