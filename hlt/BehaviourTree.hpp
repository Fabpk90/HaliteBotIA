//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_BEHAVIOURTREE_HPP
#define MYBOT_BEHAVIOURTREE_HPP
#include "Blackboard.hpp"
#include "Node.hpp"
#include "game.hpp"

class BehaviourTree
{
public:
    BehaviourTree(hlt::Game* game) : m_game(game){}
    void addNode(Node* newNode)
    {
        m_nodes.push_back(newNode);
    }
private:
    hlt::Game* m_game;
    std::vector<Node*> m_nodes;
    Blackboard* m_blackboard;
};


#endif //MYBOT_BEHAVIOURTREE_HPP
