//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_SELECTOR_HPP
#define MYBOT_SELECTOR_HPP
#include "Node.hpp"

class Selector : public Node
{
public:
    Selector(hlt::Game *game, Node* nodePtr, const int &nbNodes);
    bool evaluate();
};


#endif //MYBOT_SELECTOR_HPP
