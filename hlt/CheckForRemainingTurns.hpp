//
// Created by fab on 06/05/2020.
//

#ifndef MYBOT_CHECKFORREMAININGTURNS_HPP
#define MYBOT_CHECKFORREMAININGTURNS_HPP

#include "CheckForThing.hpp"
#include "constants.hpp"

class CheckForRemainingTurns : public CheckForThing
{
public:

    CheckForRemainingTurns(Blackboard* b, int amount, ECmpType type) : CheckForThing(b, amount, type) {};

    bool evaluate() override
    {
        int remainingTurns = hlt::constants::MAX_TURNS - m_blackboard->m_game->turn_number;

        if(m_type == GREATER)
            return remainingTurns > m_amount;
        return remainingTurns < m_amount;
    }
};

#endif //MYBOT_CHECKFORREMAININGTURNS_HPP
