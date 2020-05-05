//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_BEHAVIOURTREE_HPP
#define MYBOT_BEHAVIOURTREE_HPP
#include "Node.hpp"
#include "game.hpp"

class BehaviourTree
{
public:
    BehaviourTree(hlt::Game* game);
    void addNode(Node* newNode);
private:
    hlt::Game* m_game;
    std::vector<Node*> m_nodes;
};


#endif //MYBOT_BEHAVIOURTREE_HPP
