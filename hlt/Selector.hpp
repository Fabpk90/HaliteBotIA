//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_SELECTOR_HPP
#define MYBOT_SELECTOR_HPP
#include "NodeContainer.hpp"

class Selector : public NodeContainer
{
public:
    Selector(hlt::Game* game, Blackboard* blackboard, hlt::Player *player, hlt::Ship *ship) : NodeContainer(game, blackboard, player, ship){}
    bool evaluate()
    {
        for(int i = 0; i < m_nodes.size(); ++i)
        {
            if(m_nodes[i]->evaluate())
                return true;
        }
        return false;
    }
};

#endif //MYBOT_SELECTOR_HPP
