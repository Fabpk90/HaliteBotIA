//
// Created by Administrateur on 07/05/2020.
//

#ifndef MYBOT_CHECKINTEREST_HPP
#define MYBOT_CHECKINTEREST_HPP

#include "Node.hpp"

class CheckInterest : public Node
{
public:
    CheckInterest(Blackboard* blackboard) : Node(blackboard){}
    bool evaluate()
    {
        hlt::Position dest(0,0);
        int interest = 0;
        for(const auto& ship : m_blackboard->m_shipsAround)
        {
            if(m_blackboard->m_game->me->ships.find(ship->id) == m_blackboard->m_game->me->ships.end()){
                //Enemy ship
                int tmpInterest = m_blackboard->m_ship->halite - ship->halite;
                if(tmpInterest > HALITE_DIFF_INTEREST && tmpInterest > interest){
                    interest = tmpInterest;
                    dest = ship->position;
                }
            }
        }
        hlt::Direction dir = m_blackboard->m_game->game_map->naive_navigate(m_blackboard->m_ship, dest);
        if(dir == hlt::Direction::STILL)
            return false;

        m_blackboard->m_commands.push_back(m_blackboard->m_ship->move(dir));
        return true;
    }
};


#endif //MYBOT_CHECKINTEREST_HPP
