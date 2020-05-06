//
// Created by Administrateur on 05/05/2020.
//

#ifndef MYBOT_ENEMYAROUND_HPP
#define MYBOT_ENEMYAROUND_HPP

#include "Node.hpp"

//Checking if the associated ship has an enemy ship around him
class EnemyAround : public Node
{
public:
    EnemyAround(hlt::Game* game, Blackboard *blackboard, hlt::Player *player) : Node(game, blackboard, player){};
    bool evaluate()
    {
        hlt::Position shipPos = m_blackboard->ship->position;

        //Checking surrounding cells
        for(int y = -ENEMY_MIN_DIST; y <= ENEMY_MIN_DIST; ++y){
            for(int x = -ENEMY_MIN_DIST; x <= ENEMY_MIN_DIST; ++x){
                hlt::Position pos = hlt::Position(m_blackboard->ship->position.x + x, m_blackboard->ship->position.y);
                //Avoiding the current ship position
                if(pos != m_blackboard->ship->position){
                    //Getting the map cell with offset, Gamemap class is already wrapping positions in "at" function
                    hlt::MapCell *currCell = m_game->game_map->at(pos);
                    if(currCell->is_occupied()){
                        //Referencing ship on the cell
                        auto ship = m_player->ships.find(currCell->ship->id);
                        //If the ship is not contained within the player ship list, it is an enemy
                        if(ship != m_player->ships.end()){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
    }
};

#endif //MYBOT_ENEMYAROUND_HPP
