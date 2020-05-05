//
// Created by Administrateur on 05/05/2020.
//

#ifndef MYBOT_NODECONTAINER_HPP
#define MYBOT_NODECONTAINER_HPP
#include "Node.hpp"
#include <vector>

class NodeContainer : public Node
{
public:
    NodeContainer(hlt::Game* game, hlt::Player *player, hlt::Ship *ship);
    void addNode(Node* newNode);
    virtual bool evaluate() = 0;
protected:
    std::vector<Node*> m_nodes;
};


#endif //MYBOT_NODECONTAINER_HPP
