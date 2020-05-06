//
// Created by fab on 05/05/2020.
//

#ifndef MYBOT_CHECKSHIPCAPACITY_HPP
#define MYBOT_CHECKSHIPCAPACITY_HPP


#include "Node.hpp"

enum ECmpType
{
    GREATER,
    LESS
};

class CheckShipCapacity : public Node
{
private:
    int m_amount;
    ECmpType m_type;
public:
    CheckShipCapacity(Blackboard* blackboard, int amount, ECmpType type)
    : Node(blackboard), m_amount(amount), m_type(type)
    {}
    bool evaluate() override
    {
        if(m_type == ECmpType::GREATER)
            return m_blackboard->m_ship->halite > m_amount;

        return m_blackboard->m_ship->halite < m_amount;
    }
};


#endif //MYBOT_CHECKSHIPCAPACITY_HPP
