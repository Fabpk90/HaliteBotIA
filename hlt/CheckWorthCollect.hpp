//
// Created by Administrateur on 09/05/2020.
//

#ifndef MYBOT_CHECKWORTHCOLLECT_HPP
#define MYBOT_CHECKWORTHCOLLECT_HPP

#include "Node.hpp"

class CheckWorthCollect : public Node
{
public:
    CheckWorthCollect(Blackboard *blackboard) : Node(blackboard){}
    bool evaluate()
    {
        hlt::Position dest(m_blackboard->m_game->me->shipyard->position);
        //Setting default unreachable distance
        int smallestDist = m_blackboard->m_game->game_map->calculate_distance(m_blackboard->m_game->me->shipyard->position, m_blackboard->m_ship->position);

        for(const auto& drop : m_blackboard->m_game->me->dropoffs)
        {
            int tmpDist = m_blackboard->m_game->game_map->calculate_distance(drop.second->position, m_blackboard->m_ship->position);
            if(tmpDist < smallestDist){
                smallestDist = tmpDist;
                dest = drop.second->position;
            }
        }

        if(m_blackboard->m_ship->halite - (smallestDist * hlt::constants::MOVE_COST_RATIO) > 0){
            return false;
        }
        return true;
    }
};


#endif //MYBOT_CHECKWORTHCOLLECT_HPP
