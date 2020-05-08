//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_BEHAVIOURTREE_HPP
#define MYBOT_BEHAVIOURTREE_HPP
#include "Blackboard.hpp"
#include "Node.hpp"

#include "SequencerFlee.hpp"

#include "game.hpp"
#include "Selector.hpp"

class BehaviourTree : public Selector
{
public:
    BehaviourTree(Blackboard* blackboard) : Selector(blackboard) {}

    ~BehaviourTree()
    {
        for(Node* n : m_nodes)
            delete n;
    }
};


#endif //MYBOT_BEHAVIOURTREE_HPP
