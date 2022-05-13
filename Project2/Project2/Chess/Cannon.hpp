//
//  Cannon.hpp
//  Chinese_Chess
//
//  Created by RinKawano on 2022/5/12.
//

#ifndef Cannon_hpp
#define Cannon_hpp

#include "Chess.hpp"

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
