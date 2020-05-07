//
// Created by Administrateur on 07/05/2020.
//

#ifndef MYBOT_SEQUENCERATTACK_HPP
#define MYBOT_SEQUENCERATTACK_HPP

#include "Sequencer.hpp"
#include "EnemyAround.hpp"
#include "Surrounded.hpp"
#include "CheckInterest.hpp"

class SequencerAttack : public Sequencer
{
public:
    SequencerAttack(Blackboard *blackboard) : Sequencer(blackboard)
    {
        addNode(new EnemyAround(blackboard));
        addNode(new Surrounded(blackboard, ALLY));
        addNode(new CheckInterest(blackboard));
    }
};


#endif //MYBOT_SEQUENCERATTACK_HPP
