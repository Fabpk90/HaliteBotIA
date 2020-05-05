//
// Created by fab on 04/05/2020.
//

#ifndef MYBOT_SELECTOR_HPP
#define MYBOT_SELECTOR_HPP
#include "NodeContainer.hpp"

class Selector : public NodeContainer
{
public:
    Selector(hlt::Game *game);
    bool evaluate();
};


#endif //MYBOT_SELECTOR_HPP
