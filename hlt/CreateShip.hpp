//
// Created by fab on 06/05/2020.
//

#ifndef MYBOT_CREATESHIP_HPP
#define MYBOT_CREATESHIP_HPP

#include "Node.hpp"

class CreateShip : public Node
{
public:

    CreateShip(Blackboard* b) : Node(b){};

    bool evaluate() override
    {
        hlt::log::log("Entering create ships");

        m_blackboard->m_commands.push_back(m_blackboard->m_game->me->shipyard->spawn());
        return true;
    }
};

#endif //MYBOT_CREATESHIP_HPP
