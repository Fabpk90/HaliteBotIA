//
// Created by Administrateur on 05/05/2020.
//

#ifndef MYBOT_SEQUENCERFLEE_HPP
#define MYBOT_SEQUENCERFLEE_HPP
#include "Sequencer.hpp"

#include "EnemyAround.hpp"
#include "Surrounded.hpp"
#include "FleeDirection.hpp"

class SequencerFlee : public Sequencer
{
public:
    SequencerFlee(Blackboard* blackboard) : Sequencer(blackboard)
    {
        addNode(new EnemyAround(blackboard));
        addNode(new Surrounded(blackboard));
        addNode(new FleeDirection(blackboard));
    }
};


#endif //MYBOT_SEQUENCERFLEE_HPP
