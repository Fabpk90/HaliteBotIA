//
// Created by fab on 06/05/2020.
//

#ifndef MYBOT_FINDHALITE_HPP
#define MYBOT_FINDHALITE_HPP

#include "Node.hpp"

class FindHalite : public Node
{
public:

    FindHalite( Blackboard* blackboard) : Node(blackboard){};

    bool evaluate() override
    {
        hlt::Position p = m_blackboard->m_game->game_map->at(m_blackboard->m_ship)->position;
        hlt::Position finalPosition = p;

        hlt::log::log("find halite");

        if(m_blackboard->m_game->game_map->at(p)->halite > 0)
        {
            hlt::log::log("halite same pos");
            m_blackboard->m_target = p;
            return true;
        }

        for (int i = -HALITE_SEARCH_PERIMETER; i < HALITE_SEARCH_PERIMETER; ++i)
        {
            for (int j = -HALITE_SEARCH_PERIMETER; j < HALITE_SEARCH_PERIMETER; ++j)
            {
                finalPosition.x = p.x + i;
                finalPosition.y = p.y + j;

                if(m_blackboard->m_game->game_map->at(finalPosition)->halite > 0)
                {
                    hlt::log::log("halite not same pos");
                    m_blackboard->m_target = finalPosition;
                    return true;
                }
            }
        }

        hlt::log::log("nothing");

        return false;
    }
};
#endif //MYBOT_FINDHALITE_HPP
