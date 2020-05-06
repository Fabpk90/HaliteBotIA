//
// Created by fab on 05/05/2020.
//

#ifndef MYBOT_MOVETOWARDS_HPP
#define MYBOT_MOVETOWARDS_HPP


#include "Node.hpp"

class MoveTowards : public Node
{
public:

    MoveTowards(Blackboard* blackboard)
    : Node(blackboard)
    {};

    bool evaluate() override
    {
        hlt::Direction d = m_blackboard->m_game->game_map->naive_navigate(m_blackboard->m_ship, m_blackboard->m_target);
        m_blackboard->m_commands.push_back(m_blackboard->m_ship->move(d));

        return true;
    };
};


#endif //MYBOT_MOVETOWARDS_HPP
