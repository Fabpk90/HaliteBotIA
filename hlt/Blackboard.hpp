//
// Created by Administrateur on 05/05/2020.
//

#ifndef MYBOT_BLACKBOARD_HPP
#define MYBOT_BLACKBOARD_HPP

#define ENEMY_MIN_DIST 4
#define HALITE_SEARCH_PERIMETER 4

#include "game.hpp"
#include <vector>

class Blackboard
{
public:
    hlt::Position target;
    std::vector<std::shared_ptr<hlt::Ship>> shipsAround;
    std::vector<hlt::Command> commands;

    std::shared_ptr<hlt::Ship> ship;
    hlt::Game* m_game;
};

#endif //MYBOT_BLACKBOARD_HPP
