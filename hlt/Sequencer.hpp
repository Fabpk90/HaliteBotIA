//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_SEQUENCER_HPP
#define MYBOT_SEQUENCER_HPP
#include "NodeContainer.hpp"

class Sequencer : public NodeContainer
{
public:
    Sequencer(hlt::Game* game, Blackboard* blackboard, hlt::Player *player, hlt::Ship *ship) : NodeContainer(game,blackboard,player,ship){}
    bool evaluate()
    {
        for(int i = 0; i < m_nodes.size(); ++i)
        {
            if(!m_nodes[i]->evaluate())
                return false;
        }
        return true;
    }
};


#endif //MYBOT_SEQUENCER_HPP
