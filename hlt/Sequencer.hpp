//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_SEQUENCER_HPP
#define MYBOT_SEQUENCER_HPP
#include "NodeContainer.hpp"

class Sequencer : public NodeContainer
{
public:
    Sequencer(Blackboard* blackboard) : NodeContainer(blackboard){}
    bool evaluate()
    {
        hlt::log::log("Entering sequencer");
        hlt::log::log(std::to_string(m_nodes.size()));
        for(unsigned int i = 0; i < m_nodes.size(); ++i)
        {
            if(!m_nodes[i]->evaluate())
                return false;
        }
        return true;
    }
};


#endif //MYBOT_SEQUENCER_HPP
