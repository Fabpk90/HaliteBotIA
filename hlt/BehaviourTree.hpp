//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_BEHAVIOURTREE_HPP
#define MYBOT_BEHAVIOURTREE_HPP
#include "Blackboard.hpp"

#include "Selector.hpp"

class BehaviourTree : public NodeContainer
{
public:
    BehaviourTree(Blackboard* blackboard) : NodeContainer(blackboard) {}

    bool evaluate() override
    {
        hlt::log::log("Starting bt " + std::to_string(m_blackboard->m_ship->id));
        /*for(int i = 0; i < m_nodes.size(); ++i)
        {
            hlt::log::log("Eval " + std::to_string(i));
            if(m_nodes[i]->evaluate())
                return true;
        }*/
        return false;
    }

    ~BehaviourTree() override
    {
        for(Node* n : m_nodes)
            delete n;
    }

    int getCountNodes() { return m_nodes.size(); }
};


#endif //MYBOT_BEHAVIOURTREE_HPP
