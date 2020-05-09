//
// Created by Administrateur on 07/05/2020.
//

#ifndef MYBOT_MOVETONEAREST_HPP
#define MYBOT_MOVETONEAREST_HPP

#include "Node.hpp"

class MoveToNearest : public Node
{
protected:
    EEntityType m_entityType;
public:
    MoveToNearest(Blackboard *blackboard, EEntityType entityType) : Node(blackboard), m_entityType(entityType){}
    bool evaluate()
    {
        hlt::Position dest(0,0);
        //Setting default unreachable distance
        int smallestDist = m_blackboard->m_game->game_map->width*m_blackboard->m_game->game_map->height;
        switch(m_entityType)
        {
            case DROPOFF:
                for(const auto& drop : m_blackboard->m_game->me->dropoffs)
                {
                    int tmpDist = m_blackboard->m_game->game_map->calculate_distance(drop.second->position, m_blackboard->m_ship->position);
                    if(tmpDist < smallestDist){
                        smallestDist = tmpDist;
                        dest = drop.second->position;
                    }
                }
                break;
            case ENEMY:
                break;
            case ALLY:
                for(const auto& ally : m_blackboard->m_game->me->ships)
                {
                    if(ally.second->id != m_blackboard->m_ship->id)
                    {
                        int tmpDist = m_blackboard->m_game->game_map->calculate_distance(ally.second->position, m_blackboard->m_ship->position);
                        if(tmpDist < smallestDist){
                            smallestDist = tmpDist;
                            dest = ally.second->position;
                        }
                    }
                }
                break;
        }
        hlt::Direction dir = m_blackboard->m_game->game_map->naive_navigate(m_blackboard->m_ship, dest);

        if(dir == hlt::Direction::STILL){
            return false;
        }

        m_blackboard->m_commands.push_back(m_blackboard->m_ship->move(dir));

        return true;
    }
};


#endif //MYBOT_MOVETONEAREST_HPP
