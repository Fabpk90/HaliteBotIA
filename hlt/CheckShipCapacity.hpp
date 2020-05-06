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

class CheckShipCapacity : Node
{
private:
    int m_amount;
    ECmpType m_type;
public:
    CheckShipCapacity(hlt::Game* game, Blackboard* blackboard, std::shared_ptr<hlt::Player> player, int amount, ECmpType type)
    : Node(game,blackboard, player), m_amount(amount), m_type(type)
    {}
    bool evaluate() override
    {
        if(m_type == ECmpType::GREATER)
            return m_blackboard->ship->halite > m_amount;

        return m_blackboard->ship->halite < m_amount;
    }
};


#endif //MYBOT_CHECKSHIPCAPACITY_HPP
