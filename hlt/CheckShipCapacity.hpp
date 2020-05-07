//
// Created by fab on 05/05/2020.
//

#ifndef MYBOT_CHECKSHIPCAPACITY_HPP
#define MYBOT_CHECKSHIPCAPACITY_HPP


#include "Node.hpp"
#include "CheckForThing.hpp"


class CheckShipCapacity : public CheckForThing
{
public:
    CheckShipCapacity(Blackboard* blackboard, int amount, ECmpType type)
    : CheckForThing(blackboard, amount, type)
    {}
    bool evaluate() override
    {
        if(m_type == ECmpType::GREATER)
            return m_blackboard->m_ship->halite > m_amount;

        return m_blackboard->m_ship->halite < m_amount;
    }
};


#endif //MYBOT_CHECKSHIPCAPACITY_HPP
