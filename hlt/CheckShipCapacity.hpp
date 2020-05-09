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
        hlt::log::log("check ship capacity");
        switch(m_type)
        {
            case ECmpType::GREATER:
                return m_blackboard->m_ship->halite > m_amount;
            case ECmpType::EQUAL:
                return m_blackboard->m_ship->halite == m_amount;
            case ECmpType::LESS:
                return m_blackboard->m_ship->halite < m_amount;
        }
        return false;
    }
};


#endif //MYBOT_CHECKSHIPCAPACITY_HPP
