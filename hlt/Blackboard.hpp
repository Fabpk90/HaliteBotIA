//
// Created by Administrateur on 05/05/2020.
//

#ifndef MYBOT_BLACKBOARD_HPP
#define MYBOT_BLACKBOARD_HPP

#define ENEMY_MIN_DIST 4
#define MIN_SHIPS 3
#define MIN_DROPOFF_DIST 5
#define HALITE_DIFF_INTEREST (hlt::constants::MAX_HALITE/2)
#define HALITE_SEARCH_PERIMETER 4

#include "game.hpp"
#include <vector>

enum EEntityType
{
    DROPOFF,
    ENEMY,
    ALLY
};

class Blackboard
{
public:
    hlt::Position m_target;
    std::vector<std::shared_ptr<hlt::Ship>> m_shipsAround;
    std::vector<hlt::Command> m_commands;

    std::shared_ptr<hlt::Ship> m_ship;
    hlt::Game* m_game;
    std::shared_ptr<hlt::Player> m_player;
};

#endif //MYBOT_BLACKBOARD_HPP
