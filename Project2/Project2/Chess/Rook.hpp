//
//  Rook.hpp
//  Chinese_Chess
//
//  Created by RinKawano on 2022/5/12.
//

#ifndef Rook_hpp
#define Rook_hpp

#include "Chess.hpp"

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
