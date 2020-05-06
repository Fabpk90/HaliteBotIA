//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_BEHAVIOURTREE_HPP
#define MYBOT_BEHAVIOURTREE_HPP
#include "Blackboard.hpp"
#include "Node.hpp"

#include "SequencerFlee.hpp"

#include "game.hpp"

class BehaviourTree
{
public:
    BehaviourTree(hlt::Game* game, Blackboard* blackboard) : m_game(game), m_blackboard(blackboard){}
    void addNode(Node* newNode)
    {
        m_nodes.push_back(newNode);
    }

    void evaluate()
    {
        for(const auto& node: m_nodes )
        {
            node->evaluate();
        }
    }

private:
    hlt::Game* m_game;
    std::vector<Node*> m_nodes;
    Blackboard* m_blackboard;
};


#endif //MYBOT_BEHAVIOURTREE_HPP
