//
//  King.hpp
//  Chinese_Chess
//
//  Created by RinKawnao on 2022/5/12.
//

#ifndef King_hpp
#define King_hpp

#include "Chess.hpp"

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
