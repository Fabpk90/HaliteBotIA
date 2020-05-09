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
    std::shared_ptr<hlt::Entity> m_nearestDropoff;
    hlt::Game* m_game;
    std::shared_ptr<hlt::Player> m_player;

    void update()
    {
        setNearestDropoff();
    }
private:
    //Finding ships around the ship member
    void setShipsAround()
    {
        for(int y = -ENEMY_MIN_DIST; y <= ENEMY_MIN_DIST; ++y){
            for(int x = -ENEMY_MIN_DIST; x <= ENEMY_MIN_DIST; ++x){
                hlt::Position pos = hlt::Position(m_ship->position.x + x, m_ship->position.y + y);
                //Avoiding the current ship position
                if(pos != m_ship->position){
                    //Getting the map cell with offset, Gamemap class is already wrapping positions in "at" function
                    hlt::MapCell *currCell = m_game->game_map->at(pos);
                    if(currCell->is_occupied()){
                        //Referencing ship on the cell
                        auto ship = m_player->ships.find(currCell->ship->id);
                        //Adding the ship to the shipsAround vector
                        m_shipsAround.push_back(ship->second);
                    }
                }
            }
        }
    }

    //Finding the closest drop off point
    void setNearestDropoff()
    {
        hlt::Position dest(m_game->me->shipyard->position);
        //Setting default unreachable distance
        int smallestDist = m_game->game_map->calculate_distance(m_game->me->shipyard->position, m_ship->position);

        for(const auto& drop : m_game->me->dropoffs)
        {
            int tmpDist = m_game->game_map->calculate_distance(drop.second->position, m_ship->position);
            if(tmpDist < smallestDist){
                smallestDist = tmpDist;
                dest = drop.second->position;
            }
        }

        m_nearestDropoff = m_game->game_map->at(dest)->structure;
    }
};

#endif //MYBOT_BLACKBOARD_HPP
