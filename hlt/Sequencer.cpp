//
// Created by fab on 04/05/2020.
//

#include "Sequencer.hpp"

Sequencer::Sequencer(hlt::Game *game) : NodeContainer(game)
{
}

bool Sequencer::evaluate()
{
    for(int i = 0; i < m_nodes.size(); ++i)
    {
        if(!m_nodes[i]->evaluate())
            return false;
    }
    return true;
}
