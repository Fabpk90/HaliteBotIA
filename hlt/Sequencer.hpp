//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_SEQUENCER_HPP
#define MYBOT_SEQUENCER_HPP
#include "NodeContainer.hpp"

class Sequencer : public NodeContainer
{
public:
    Sequencer(hlt::Game* game, hlt::Player *player, hlt::Ship *ship);
    bool evaluate();
};


#endif //MYBOT_SEQUENCER_HPP
