//
// Created by fab on 05/05/2020.
//

#include "CheckShipCapacity.hpp"

bool CheckShipCapacity::evaluate()
{
    if(m_type == ECmpType::GREATER)
        return m_ship->halite > m_amount;

    return m_ship->halite < m_amount;
}
