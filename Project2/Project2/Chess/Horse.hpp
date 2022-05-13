//
//  Horse.hpp
//  Chinese_Chess
//
//  Created by RinKawano on 2022/5/12.
//

#ifndef Horse_hpp
#define Horse_hpp

#include "Chess.hpp"

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
