//
// Created by fab on 08/05/2020.
//

#ifndef MYBOT_SEQUENCERWAIT_HPP
#define MYBOT_SEQUENCERWAIT_HPP

#include "Sequencer.hpp"
#include "StayOnCell.hpp"

class SequencerWait : public Sequencer
{
public:
    SequencerWait(Blackboard* b) : Sequencer(b)
    {
        addNode(new StayOnCell(b));
    }
};
#endif //MYBOT_SEQUENCERWAIT_HPP
