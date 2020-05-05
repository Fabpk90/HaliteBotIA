//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_NODE_HPP
#define MYBOT_NODE_HPP

#include "Blackboard.hpp"
#include "game.hpp"


class Node
{
public:
    Node(hlt::Game* game, Blackboard* blackboard, hlt::Player *player, hlt::Ship *ship) : m_game(game), m_blackboard(blackboard), m_player(player), m_ship(ship){}
    virtual bool evaluate() = 0;
protected:
    hlt::Game* m_game;
    hlt::Ship* m_ship;
    hlt::Player* m_player;
    Blackboard* m_blackboard;
};


#endif //MYBOT_NODE_HPP
