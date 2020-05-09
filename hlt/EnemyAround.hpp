//
// Created by Administrateur on 05/05/2020.
//

#ifndef MYBOT_ENEMYAROUND_HPP
#define MYBOT_ENEMYAROUND_HPP

#include "Node.hpp"

//Checking if the associated ship has an enemy ship around him
class EnemyAround : public Node
{
public:
    EnemyAround(Blackboard *blackboard) : Node(blackboard){};
    bool evaluate()
    {
        for(const auto& ship : m_blackboard->m_shipsAround)
        {
            //If the ship is not contained within the player ship list, it is an enemy
            if(m_blackboard->m_player->ships.find(ship->id) == m_blackboard->m_player->ships.end())
                return true;
        }
        return false;
    }
};

#endif //MYBOT_ENEMYAROUND_HPP
