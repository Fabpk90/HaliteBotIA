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
    SequencerFlee(hlt::Game* game, Blackboard* blackboard, std::shared_ptr<hlt::Player> player) : Sequencer(game,blackboard,player)
    {
        addNode(new EnemyAround(game, blackboard, player));
        addNode(new Surrounded(game, blackboard, player));
        addNode(new FleeDirection(game, blackboard, player));
    }
};


#endif //MYBOT_SEQUENCERFLEE_HPP
