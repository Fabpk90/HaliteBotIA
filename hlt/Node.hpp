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
    Node(Blackboard* blackboard) : m_blackboard(blackboard){}
    virtual bool evaluate() = 0;
    virtual ~Node() = default;
protected:
    Blackboard* m_blackboard;
};


#endif //MYBOT_NODE_HPP
