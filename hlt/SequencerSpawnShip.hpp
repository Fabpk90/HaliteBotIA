//
// Created by fab on 08/05/2020.
//

#ifndef MYBOT_SEQUENCERSPAWNSHIP_HPP
#define MYBOT_SEQUENCERSPAWNSHIP_HPP

#include "Sequencer.hpp"
#include "CheckHalite.hpp"
#include "CheckRemaningShips.hpp"
#include "CheckForRemainingTurns.hpp"
#include "CreateShip.hpp"
#include "CheckForEmptyCell.hpp"

class SequencerSpawnShip : public Sequencer
{
public:
    SequencerSpawnShip(Blackboard* b) : Sequencer(b)
    {
        addNode(new CheckForEmptyCell(b));
        addNode(new CheckHalite(b, 1000, GREATER));
        addNode(new CheckRemainingShips(b, 8, LESS));
        addNode(new CheckForRemainingTurns(b, 10, GREATER));
        addNode(new CreateShip(b));
    }
};
#endif //MYBOT_SEQUENCERSPAWNSHIP_HPP
