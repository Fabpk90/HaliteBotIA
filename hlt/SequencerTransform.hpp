//
// Created by Administrateur on 07/05/2020.
//

#ifndef MYBOT_SEQUENCERTRANSFORM_HPP
#define MYBOT_SEQUENCERTRANSFORM_HPP

#include "hlt/Sequencer.hpp"
#include "hlt/CheckShipCapacity.hpp"
#include "hlt/CheckRemaningShips.hpp"
#include "hlt/CheckHalite.hpp"
#include "hlt/FarEnoughFrom.hpp"
#include "hlt/DropOffTransform.hpp"

class SequencerTransform : public Sequencer
{
public:
    SequencerTransform(Blackboard* blackboard) : Sequencer(blackboard)
    {
        addNode(new CheckShipCapacity(blackboard, hlt::constants::MAX_HALITE, EQUAL));
        addNode(new CheckRemainingShips(blackboard, MIN_SHIPS, GREATER));
        addNode(new CheckHalite(blackboard, hlt::constants::DROPOFF_COST, GREATER));
        addNode(new FarEnoughFrom(blackboard, DROPOFF, MIN_DROPOFF_DIST));
        addNode(new DropOffTransform(blackboard));
    };

};


#endif //MYBOT_SEQUENCERTRANSFORM_HPP
