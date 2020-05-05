//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_SEQUENCER_HPP
#define MYBOT_SEQUENCER_HPP
#include "Node.hpp"


class Sequencer : public Node
{
public:
    Sequencer(hlt::Game *game, Node *nodes, const int &nbNodes);
    bool evaluate();
};


#endif //MYBOT_SEQUENCER_HPP
