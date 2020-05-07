//
// Created by Administrateur on 07/05/2020.
//

#ifndef MYBOT_FARENOUGHFROM_HPP
#define MYBOT_FARENOUGHFROM_HPP

#include "hlt/Node.hpp"

enum EEntityType
{
    DROPOFF,
    ENEMY,
    ALLY
};

class FarEnoughFrom : public Node
{
protected:
    EEntityType m_entityType;
    int m_minDist;
public:
    FarEnoughFrom(Blackboard* blackboard, EEntityType entityType, int minDist) : Node(blackboard), m_entityType(entityType), m_minDist(minDist){}
    bool evaluate()
    {
        switch(m_entityType)
        {
            case DROPOFF:
                for(const auto& dropoff : m_blackboard->m_game->me->dropoffs)
                {
                    if(m_blackboard->m_game->game_map->calculate_distance(m_blackboard->m_ship->position, dropoff.second->position) < m_minDist)
                        return false;
                }
                return true;
            case ENEMY:
                //TODO : Access enemy ships
                return false;
            case ALLY:
                for(const auto& ally : m_blackboard->m_game->me->ships)
                {
                    if(m_blackboard->m_game->game_map->calculate_distance(m_blackboard->m_ship->position, ally.second->position) < m_minDist)
                        return false;
                }
                return true;
        }
        return false;
    }
};


#endif //MYBOT_FARENOUGHFROM_HPP
