//
//  Minister.hpp
//  Chinese_Chess
//
//  Created by RinKawano on 2022/5/12.
//

#ifndef Minister_hpp
#define Minister_hpp

#include "Chess.hpp"

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
