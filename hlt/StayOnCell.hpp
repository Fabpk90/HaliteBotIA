//
// Created by fab on 05/05/2020.
//

#ifndef MYBOT_STAYONCELL_HPP
#define MYBOT_STAYONCELL_HPP


#include "Node.hpp"

class StayOnCell : Node
{
public:
    StayOnCell(hlt::Game* game,Blackboard* blackboard, std::shared_ptr<hlt::Player> player)
    : Node(game, blackboard, player)
    {};

    bool evaluate() override
    {
        m_blackboard->m_commands.push_back(m_blackboard->m_ship->stay_still());
    }
};


#endif //MYBOT_STAYONCELL_HPP
