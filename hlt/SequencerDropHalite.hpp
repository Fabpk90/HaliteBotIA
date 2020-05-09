//
// Created by Administrateur on 07/05/2020.
//

#ifndef MYBOT_SEQUENCERDROPHALITE_HPP
#define MYBOT_SEQUENCERDROPHALITE_HPP

#include "Sequencer.hpp"
#include "CheckShipCapacity.hpp"
#include "CheckWorthDrop.hpp"
#include "MoveToNearest.hpp"

class SequencerDropHalite : public Sequencer
{
public:
    SequencerDropHalite(Blackboard *blackboard) : Sequencer(blackboard)
    {
        addNode(new CheckShipCapacity(blackboard, 600, GREATER));
        //addNode(new CheckShipCapacity(blackboard, hlt::constants::MAX_HALITE, EQUAL));
        addNode(new CheckWorthDrop(blackboard));
        addNode(new MoveToNearest(blackboard, DROPOFF));
    }
};


#endif //MYBOT_SEQUENCERDROPHALITE_HPP
