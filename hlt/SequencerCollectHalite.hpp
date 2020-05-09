//
// Created by fab on 08/05/2020.
//

#ifndef MYBOT_SEQUENCERCOLLECTHALITE_HPP
#define MYBOT_SEQUENCERCOLLECTHALITE_HPP

#include "Sequencer.hpp"
#include "CheckShipCapacity.hpp"
#include "CheckWorthCollect.hpp"
#include "FindHalite.hpp"
#include "MoveTowards.hpp"

class SequencerCollectHalite : public Sequencer
{
public:
    SequencerCollectHalite(Blackboard* blackboard) : Sequencer(blackboard)
    {
        addNode(new CheckShipCapacity(blackboard, hlt::constants::MAX_HALITE, LESS));
        addNode(new CheckWorthCollect(blackboard));
        addNode(new FindHalite(blackboard));
        addNode(new MoveTowards(blackboard));
    }
};
#endif //MYBOT_SEQUENCERCOLLECTHALITE_HPP
