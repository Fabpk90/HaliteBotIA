//
// Created by fab on 04/05/2020.
//

#include "BehaviourTree.hpp"

BehaviourTree::BehaviourTree(hlt::Game* game)
{
    m_game = game;
}

void BehaviourTree::addNode(Node *newNode)
{
    m_nodes.push_back(newNode);
}
