//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_SELECTOR_HPP
#define MYBOT_SELECTOR_HPP
#include "NodeContainer.hpp"

class Selector : public NodeContainer
{
public:
    Selector(Blackboard* blackboard) : NodeContainer(blackboard){};
    bool evaluate() override
    {
        hlt::log::log("Starting bt " + std::to_string(m_blackboard->m_ship->id));
        for(int i = 0; i < m_nodes.size(); ++i)
        {
            hlt::log::log("Eval " + std::to_string(i));
            if(m_nodes[i]->evaluate())
                return true;
        }
        return false;
    }
};

#endif //MYBOT_SELECTOR_HPP
