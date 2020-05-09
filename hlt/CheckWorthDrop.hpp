//
// Created by Administrateur on 09/05/2020.
//

#ifndef MYBOT_CHECKWORTHDROP_HPP
#define MYBOT_CHECKWORTHDROP_HPP

#include "CheckWorthCollect.hpp"

class CheckWorthDrop : public CheckWorthCollect{
public:
    CheckWorthDrop(Blackboard *blackboard) : CheckWorthCollect(blackboard){}
    bool evaluate()
    {
        return !CheckWorthCollect::evaluate();
    }
};


#endif //MYBOT_CHECKWORTHDROP_HPP
