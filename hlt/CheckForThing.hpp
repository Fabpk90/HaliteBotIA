//
// Created by fab on 06/05/2020.
//

#ifndef MYBOT_CHECKFORTHING_HPP
#define MYBOT_CHECKFORTHING_HPP

#include "Node.hpp"

enum ECmpType
{
    EQUAL,
    GREATER,
    LESS
};

class CheckForThing : public Node
{
protected:
    int m_amount;
    ECmpType m_type;
public:

    CheckForThing(Blackboard* b, int amount, ECmpType type) : Node(b), m_amount(amount), m_type(type) {};

    virtual bool evaluate() = 0;
};

#endif //MYBOT_CHECKFORTHING_HPP
