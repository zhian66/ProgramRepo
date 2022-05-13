//  Created by RinKawano on 2022/5/12.

#ifndef Chess_hpp
#define Chess_hpp

typedef struct pair {
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


#ifndef King_hpp
#define King_hpp

class King : public Chess {
public:
    King();
    King(const King& king);
    King(const int& X, const int& Y);
    King(const pair& pos);
    ~King();
    King& operator= (const King& king);
    King& operator= (const pair& pos);
    void getSuggestion();
};

#endif /* King_hpp */



#ifndef Pawn_hpp
#define Pawn_hpp

class Pawn : public Chess {
public:
    Pawn();
    Pawn(const Pawn& pawn);
    Pawn(const int& X, const int& Y);
    Pawn(const pair& pos);
    ~Pawn();
    Pawn& operator= (const Pawn& pawn);
    Pawn& operator= (const pair& pos);
    void getSuggestion();
};

#endif /* Pawn_hpp */


#ifndef Rook_hpp
#define Rook_hpp

class Rook : public Chess {
public:
    Rook();
    Rook(const Rook& rook);
    Rook(const int& X, const int& Y);
    Rook(const pair& pos);
    ~Rook();
    Rook& operator= (const Rook& rook);
    Rook& operator= (const pair& pos);
    void getSuggestion();
};

#endif /* Rook_hpp */



#ifndef Minister_hpp
#define Minister_hpp

class Minister : public Chess {
public:
    Minister();
    Minister(const Minister& minister);
    Minister(const int& X, const int& Y);
    Minister(const pair& pos);
    ~Minister();
    Minister& operator= (const Minister& minister);
    Minister& operator= (const pair& pos);
    void getSuggestion();
};

#endif /* Minister_hpp */

#ifndef Horse_hpp
#define Horse_hpp

class Horse : public Chess {
public:
    Horse();
    Horse(const Horse& horse);
    Horse(const int& X, const int& Y);
    Horse(const pair& pos);
    ~Horse();
    Horse& operator= (const Horse& horse);
    Horse& operator= (const pair& pos);
    void getSuggestion();
};

#endif /* Horse_hpp */


#ifndef Cannon_hpp
#define Cannon_hpp

class Cannon : public Chess {
public:
    Cannon();
    Cannon(const Cannon& cannon);
    Cannon(const int& X, const int& Y);
    Cannon(const pair& pos);
    ~Cannon();
    Cannon& operator= (const Cannon& cannon);
    Cannon& operator= (const pair& pos);
    void getSuggestion();
};

#endif /* Cannon_hpp */



#ifndef Guard_hpp
#define Guard_hpp

class Guard : public Chess {
public:
    Guard();
    Guard(const Guard& guard);
    Guard(const int& X, const int& Y);
    Guard(const pair& pos);
    ~Guard();
    Guard& operator= (const Guard& guard);
    Guard& operator= (const pair& pos);
    void getSuggestion();
};

#endif /* Guard_hpp */
