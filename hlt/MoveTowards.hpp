//
// Created by fab on 05/05/2020.
//

#ifndef MYBOT_MOVETOWARDS_HPP
#define MYBOT_MOVETOWARDS_HPP


#include "Node.hpp"

class MoveTowards : Node
{
public:

    MoveTowards(hlt::Game* game,Blackboard* blackboard, std::shared_ptr<hlt::Player> player)
    : Node(game, blackboard, player)
    {};

    bool evaluate() override
    {
        m_blackboard->commands.push_back(m_blackboard->)
    };
};


#endif //MYBOT_MOVETOWARDS_HPP
