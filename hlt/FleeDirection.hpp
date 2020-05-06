//
// Created by Administrateur on 05/05/2020.
//

#ifndef MYBOT_FLEEDIRECTION_HPP
#define MYBOT_FLEEDIRECTION_HPP

#include "Node.hpp"
#include <algorithm>

class FleeDirection : public Node
{
public:
    FleeDirection(hlt::Game* game, Blackboard* blackboard, hlt::Player *player, hlt::Ship *ship) : Node(game, blackboard, player, ship){};
    bool evaluate()
    {
        int xWeight = 0, yWeight = 0;
        //Calculating weight for each direction considering the coordinates of the ships around
        for(const auto& ship : m_blackboard->shipsAround)
        {
            auto tShip = m_player->ships.find(ship->id);
            //If the ship is not contained within the player ship list, it is an enemy
            bool isEnemy = (tShip == m_player->ships.end());

            if(isEnemy){
                if(ship->position.x > m_ship->position.x)
                    --xWeight;
                    //(isEnemy) ? ++rightWeight : --rightWeight;
                if(ship->position.x < m_ship->position.x)
                    ++xWeight;
                    //(isEnemy) ? ++leftWeight : --leftWeight;
                if(ship->position.y > m_ship->position.y)
                    --yWeight;
                    //(isEnemy) ? ++upWeight : --upWeight;
                if(ship->position.y < m_ship->position.y)
                    ++yWeight;
                    //(isEnemy) ? ++downWeight : --downWeight;
            }
        }
        int x = 0, y = 0;

        //Clamping to 1 cell unit max
        x = std::max(-1, std::min(xWeight, 1));
        if(x == 0)
            y = std::max(-1, std::min(yWeight, 1));

        //Setting the new target in the blackboard
        hlt::Position target = hlt::Position(m_ship->position.x + x, m_ship->position.y + y);
        m_blackboard->target = target;

        return true;
    }
};


#endif //MYBOT_FLEEDIRECTION_HPP
