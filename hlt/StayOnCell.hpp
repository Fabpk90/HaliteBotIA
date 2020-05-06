//
// Created by fab on 05/05/2020.
//

#ifndef MYBOT_STAYONCELL_HPP
#define MYBOT_STAYONCELL_HPP


#include "Node.hpp"

class StayOnCell : Node
{
public:
    StayOnCell(hlt::Game* game,Blackboard* blackboard, hlt::Player *player, hlt::Ship *ship)
    : Node(game, blackboard, player, ship)
    {};

    bool evaluate() override;
};


#endif //MYBOT_STAYONCELL_HPP
