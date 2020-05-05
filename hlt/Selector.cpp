//
// Created by fab on 04/05/2020.
//

#include "Selector.hpp"


Selector::Selector(hlt::Game *game, Node *nodes, const int &nbNodes) : Node(game)
{
    //Adding each node in the vector
    m_nodes.reserve(nbNodes);
    for(int i = 0; i < nbNodes; ++i)
        m_nodes.push_back(&nodes[i]);
}

bool Selector::evaluate()
{
    for(int i = 0; i < m_nodes.size(); ++i)
    {
        if(m_nodes[i]->evaluate())
            return true;
    }
    return false;
}
