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
    NodeContainer(Blackboard* blackboard) : Node(blackboard){}
    void addNode(Node* newNode)
    {
        m_nodes.push_back(newNode);
    }
    virtual bool evaluate() = 0;
protected:
    std::vector<Node*> m_nodes;
};


#endif //MYBOT_NODECONTAINER_HPP
