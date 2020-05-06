//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_SEQUENCER_HPP
#define MYBOT_SEQUENCER_HPP
#include "NodeContainer.hpp"

class Sequencer : public NodeContainer
{
public:
    Sequencer(hlt::Game* game, Blackboard* blackboard, std::shared_ptr<hlt::Player> player) : NodeContainer(game,blackboard,player){}
    bool evaluate()
    {
        for(unsigned int i = 0; i < m_nodes.size(); ++i)
        {
            if(!m_nodes[i]->evaluate())
                return false;
        }
        return true;
    }
};


#endif //MYBOT_SEQUENCER_HPP
