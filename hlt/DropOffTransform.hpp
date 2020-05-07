//
// Created by Administrateur on 07/05/2020.
//

#ifndef MYBOT_DROPOFFTRANSFORM_HPP
#define MYBOT_DROPOFFTRANSFORM_HPP

#include "hlt/Node.hpp"

class DropOffTransform : public Node
{
public:
    DropOffTransform(Blackboard *blackboard) : Node(blackboard){}
    bool evaluate()
    {
        m_blackboard->m_commands.push_back(m_blackboard->m_ship->make_dropoff());
        return true;
    }
};


#endif //MYBOT_DROPOFFTRANSFORM_HPP
