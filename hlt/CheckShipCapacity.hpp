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
    CheckShipCapacity(hlt::Game* game, Blackboard* blackboard, hlt::Player *player, hlt::Ship *ship, int amount, ECmpType type)
    : Node(game,blackboard, player, ship), m_amount(amount), m_type(type)
    {}
    bool evaluate() override;
};


#endif //MYBOT_CHECKSHIPCAPACITY_HPP
