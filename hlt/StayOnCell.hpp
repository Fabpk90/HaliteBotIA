//
// Created by fab on 05/05/2020.
//

#ifndef MYBOT_STAYONCELL_HPP
#define MYBOT_STAYONCELL_HPP


#include "Node.hpp"

class StayOnCell : public Node
{
public:
    StayOnCell(Blackboard* blackboard)
    : Node(blackboard)
    {};

    bool evaluate() override
    {
        m_blackboard->m_commands.push_back(m_blackboard->m_ship->stay_still());
        return true;
    };
};


#endif //MYBOT_STAYONCELL_HPP
