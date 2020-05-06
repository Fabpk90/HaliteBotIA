//
// Created by fab on 06/05/2020.
//

#ifndef MYBOT_FINDHALITE_HPP
#define MYBOT_FINDHALITE_HPP

#include "Node.hpp"

class FindHalite : Node
{

    FindHalite(hlt::Game* game, Blackboard* blackboard, std::shared_ptr<hlt::Player> player) : Node(game, blackboard, player){};

    bool evaluate() override
    {
        hlt::Position p = m_blackboard->m_game->game_map->at(m_blackboard->ship)->position;
        int maxHalite = -1;
        hlt::Position finalPosition = p;

        for (int i = 0; i < HALITE_SEARCH_PERIMETER; ++i)
        {
            for (int j = 0; j < HALITE_SEARCH_PERIMETER; ++j)
            {
                hlt::Position position = p;

                position.x += i;
                position.y += j;

                auto* cell = m_blackboard->m_game->game_map->at(position);

                if(!cell->is_occupied() && cell->halite >= maxHalite)
                {
                    finalPosition = position;
                    maxHalite = cell->halite;
                }
            }
        }

        m_blackboard->target = finalPosition;

        return maxHalite != -1;
    }
};
#endif //MYBOT_FINDHALITE_HPP
