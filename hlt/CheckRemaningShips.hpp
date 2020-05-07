//
// Created by fab on 06/05/2020.
//

#ifndef MYBOT_CHECKREMANINGSHIPS_HPP
#define MYBOT_CHECKREMANINGSHIPS_HPP

#include "CheckForThing.hpp"

class CheckRemainingShips : public CheckForThing
{
public:

    CheckRemainingShips(Blackboard* b, int amount, ECmpType type) : CheckForThing(b, amount, type){};

    bool evaluate() override
    {
        hlt::log::log("Entering Check ships");

        if(m_type == GREATER)
            return m_blackboard->m_game->me->ships.size() > m_amount;

        return m_blackboard->m_game->me->ships.size() < m_amount;
    }

    ~CheckRemainingShips() override = default;
};

#endif //MYBOT_CHECKREMANINGSHIPS_HPP
