//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_NODE_HPP
#define MYBOT_NODE_HPP
#include "game.hpp"
#include <vector>


class Node
{
public:
    Node(hlt::Game* game);
    virtual bool evaluate() = 0;
protected:
    hlt::Game* m_game;
    std::vector<Node*> m_nodes;
};


#endif //MYBOT_NODE_HPP
