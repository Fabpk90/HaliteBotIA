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
        if(m_blackboard->m_ship->position ==  m_blackboard->m_target)
            m_blackboard->m_commands.push_back(m_blackboard->m_ship->stay_still());
        else
        {
            if( m_blackboard->m_game->game_map->at(m_blackboard->m_ship->position)->halite *.10f < m_blackboard->m_ship->halite)
            {
                hlt::Direction d = m_blackboard->m_game->game_map->naive_navigate(m_blackboard->m_ship, m_blackboard->m_target);
                m_blackboard->m_commands.push_back(m_blackboard->m_ship->move(d));
            }
            else
                m_blackboard->m_commands.push_back(m_blackboard->m_ship->stay_still());
        }
        return true;
    };
};


#endif //MYBOT_MOVETOWARDS_HPP
