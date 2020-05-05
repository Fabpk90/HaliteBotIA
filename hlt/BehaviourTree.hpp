//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_BEHAVIOURTREE_HPP
#define MYBOT_BEHAVIOURTREE_HPP


#include "Node.hpp"
#include <list>

class BehaviourTree
{
public:
    std::list<Node*> nodes;

    BehaviourTree() = default;

    void analyse();
    void addNode(Node* n) { nodes.push_back(n); }
};


#endif //MYBOT_BEHAVIOURTREE_HPP
