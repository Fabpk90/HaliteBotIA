//
// Created by fab on 05/05/2020.
//

#ifndef MYBOT_MOVETOWARDS_HPP
#define MYBOT_MOVETOWARDS_HPP


#include "Node.hpp"

class MoveTowards : Node
{
public:

    MoveTowards(hlt::Game* game,Blackboard* blackboard, std::shared_ptr<hlt::Player> player)
    : Node(game, blackboard, player)
    {};

    bool evaluate() override
    {
        hlt::Direction d = m_blackboard->m_game->game_map->naive_navigate(m_blackboard->ship, m_blackboard->target);
        m_blackboard->commands.push_back(m_blackboard->ship->move(d));

        return true;
    };
};


#endif //MYBOT_MOVETOWARDS_HPP
