//
// Created by Administrateur on 05/05/2020.
//

#ifndef MYBOT_SEQUENCERFLEE_HPP
#define MYBOT_SEQUENCERFLEE_HPP
#include "Sequencer.hpp"

class SequencerFlee : Sequencer
{
public:
    SequencerFlee(hlt::Game* game, Blackboard* blackboard, hlt::Player *player, hlt::Ship *ship) : Sequencer(game,blackboard,player,ship){}
};


#endif //MYBOT_SEQUENCERFLEE_HPP
