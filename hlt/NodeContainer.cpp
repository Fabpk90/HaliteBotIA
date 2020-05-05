//
// Created by Administrateur on 05/05/2020.
//

#include "NodeContainer.hpp"

NodeContainer::NodeContainer(hlt::Game* game, hlt::Player *player, hlt::Ship *ship) : Node(game, player, ship)
{
}

void NodeContainer::addNode(Node *newNode)
{
    m_nodes.push_back(newNode);
}