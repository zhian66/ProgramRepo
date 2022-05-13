//
//  Guard.hpp
//  Chinese_Chess
//
//  Created by RinKawano on 2022/5/12.
//

#ifndef Guard_hpp
#define Guard_hpp

#include "Chess.hpp"

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
