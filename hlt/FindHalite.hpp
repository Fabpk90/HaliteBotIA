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
        std::shared_ptr<hlt::Ship> ship = m_blackboard->m_ship;

        hlt::Position p = ship->position;
        hlt::Position idealPos = p;

        int idealTravelCost = movementCost(idealPos, m_blackboard->m_nearestDropoff->position) - haliteOn(p);
        bool foundSomething = false;

        hlt::log::log("find halite");

        for (int i = -HALITE_SEARCH_PERIMETER; i < HALITE_SEARCH_PERIMETER; ++i)
        {
            for (int j = -HALITE_SEARCH_PERIMETER; j < HALITE_SEARCH_PERIMETER; ++j)
            {
                hlt::Position targetPos = hlt::Position(p.x + i, p.y + j);
                //If the targeted position isn't occupied
                if(!m_blackboard->m_game->game_map->at(targetPos)->is_occupied() && haliteOn(targetPos) > 0)
                {
                    if(!foundSomething)
                        foundSomething = true;
                    //Travel cost in halite to the targeted position
                    int travelCostFromCurrent = movementCost(p, targetPos) + movementCost(targetPos, m_blackboard->m_nearestDropoff->position) - haliteOn(targetPos);

                    if(travelCostFromCurrent < idealTravelCost)
                    {
                        idealPos = targetPos;
                        idealTravelCost = travelCostFromCurrent;
                    }
                }
            }
        }
        m_blackboard->m_target = idealPos;
        hlt::log::log("nothing");

        return foundSomething;
    }
private:
    int movementCost(hlt::Position from, hlt::Position to)
    {
        return m_blackboard->m_game->game_map->calculate_distance(from, to) * hlt::constants::MOVE_COST_RATIO;
    }

    int haliteOn(hlt::Position position)
    {
        return m_blackboard->m_game->game_map->at(position)->halite;
    }
};
#endif //MYBOT_FINDHALITE_HPP
