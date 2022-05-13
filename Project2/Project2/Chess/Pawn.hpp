//
//  Pawn.hpp
//  Chinese_Chess
//
//  Created by RinKawano on 2022/5/12.
//

#ifndef Pawn_hpp
#define Pawn_hpp

#include "Chess.hpp"

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
