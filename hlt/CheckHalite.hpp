//
// Created by fab on 06/05/2020.
//

#ifndef MYBOT_CHECKHALITE_HPP
#define MYBOT_CHECKHALITE_HPP

#include "CheckForThing.hpp"


class CheckHalite : public CheckForThing
{
public:
    CheckHalite(Blackboard* b, int amount, ECmpType type) : CheckForThing(b, amount, type){};

    bool evaluate() override
    {
        switch(m_type)
        {
            case ECmpType::GREATER:
                return m_blackboard->m_game->me->halite > m_amount;
            case ECmpType::EQUAL:
                return m_blackboard->m_ship->halite == m_amount;
            case ECmpType::LESS:
                return m_blackboard->m_game->me->halite < m_amount;
        }
        return false;
    }

};
#endif //MYBOT_CHECKHALITE_HPP