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
    FleeDirection(Blackboard* blackboard) : Node(blackboard){};
    bool evaluate()
    {
        int xWeight = 0, yWeight = 0;
        //Calculating weight for each direction considering the coordinates of the ships around
        for(const auto& ship : m_blackboard->m_shipsAround)
        {
            auto tShip = m_blackboard->m_player->ships.find(ship->id);
            //If the ship is not contained within the player ship list, it is an enemy
            bool isEnemy = (tShip == m_blackboard->m_player->ships.end());

            if(isEnemy){
                if(ship->position.x > m_blackboard->m_ship->position.x)
                    --xWeight;
                    //(isEnemy) ? ++rightWeight : --rightWeight;
                if(ship->position.x < m_blackboard->m_ship->position.x)
                    ++xWeight;
                    //(isEnemy) ? ++leftWeight : --leftWeight;
                if(ship->position.y > m_blackboard->m_ship->position.y)
                    --yWeight;
                    //(isEnemy) ? ++upWeight : --upWeight;
                if(ship->position.y < m_blackboard->m_ship->position.y)
                    ++yWeight;
                    //(isEnemy) ? ++downWeight : --downWeight;
            }
        }
        int x = 0, y = 0;

        //Clamping to 1 cell unit max
        x = std::max(-1, std::min(xWeight, 1));
        if(x == 0){
            y = std::max(-1, std::min(yWeight, 1));
        }

        //Setting the new target in the blackboard
        hlt::Position target = hlt::Position(m_blackboard->ship->position.x + x, m_blackboard->ship->position.y + y);
        m_blackboard->target = target;
        hlt::Direction dir = m_game->game_map->naive_navigate(m_blackboard->ship, target);
        hlt::MapCell* cell = m_game->game_map->at(target);

        if(x == 0 && y == 0 || cell->is_occupied()){
            m_blackboard->commands.push_back(m_blackboard->ship->stay_still());
        }else{
            m_blackboard->commands.push_back(m_blackboard->ship->move(dir));
        }

        return true;
    }
};


#endif //MYBOT_FLEEDIRECTION_HPP
