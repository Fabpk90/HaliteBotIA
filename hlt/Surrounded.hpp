//
// Created by Administrateur on 05/05/2020.
//

#ifndef MYBOT_SURROUNDED_HPP
#define MYBOT_SURROUNDED_HPP

#include "Node.hpp"

//Checking if the associated ship is surrounded by more enemy ships than ally ones
class Surrounded : public Node
{
protected:
    EEntityType m_entityType;
public:
    Surrounded(Blackboard* blackboard, EEntityType entityType) : Node(blackboard){};
    bool evaluate()
    {
        m_blackboard->m_shipsAround.clear();
        int alliesAround = 0, enemiesAround = 0;
        hlt::Position shipPos = m_blackboard->m_ship->position;

        for(const auto& ship : m_blackboard->m_shipsAround)
        {
            //If the ship is not contained within the player ship list, it is an enemy
            if(m_blackboard->m_player->ships.find(ship->id) == m_blackboard->m_player->ships.end())
                ++enemiesAround;
            else
                ++alliesAround;
        }
        return (m_entityType == ENEMY) ? (enemiesAround > alliesAround) : (enemiesAround < alliesAround);
    }
};

#endif //MYBOT_SURROUNDED_HPP
