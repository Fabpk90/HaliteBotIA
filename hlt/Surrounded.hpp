//
// Created by Administrateur on 05/05/2020.
//

#ifndef MYBOT_SURROUNDED_HPP
#define MYBOT_SURROUNDED_HPP

#include "Node.hpp"

//Checking if the associated ship is surrounded by more enemy ships than ally ones
class Surrounded : public Node
{
protected:
    EEntityType m_entityType;
public:
    Surrounded(Blackboard* blackboard, EEntityType entityType) : Node(blackboard){};
    bool evaluate()
    {
        m_blackboard->m_shipsAround.clear();
        int alliesAround = 0, enemiesAround = 0;
        hlt::Position shipPos = m_blackboard->m_ship->position;

        //Checking surrounding cells
        for(int y = -ENEMY_MIN_DIST; y <= ENEMY_MIN_DIST; ++y){
            for(int x = -ENEMY_MIN_DIST; x <= ENEMY_MIN_DIST; ++x){
                hlt::Position pos = hlt::Position(m_blackboard->m_ship->position.x + x, m_blackboard->m_ship->position.y);
                //Avoiding the current ship position
                if(pos != m_blackboard->m_ship->position){
                    //Getting the map cell with offset, Gamemap class is already wrapping positions in "at" function
                    hlt::MapCell *currCell = m_blackboard->m_game->game_map->at(pos);
                    if(currCell->is_occupied()){
                        //Referencing ship on the cell
                        auto ship = m_blackboard->m_player->ships.find(currCell->ship->id);
                        //Adding the ship to the shipsAround vector in the blackboard

                        //TODO : The shipsAround vector should be updated before entering the tree
                        m_blackboard->m_shipsAround.push_back(ship->second);
                        //If the ship is not contained within the player ship list, it is an enemy
                        if(ship != m_blackboard->m_player->ships.end()){
                            ++enemiesAround;
                        }else{
                            ++alliesAround;
                        }
                    }
                }
            }
        }
        return (m_entityType == ENEMY) ? (enemiesAround > alliesAround) : (enemiesAround < alliesAround);
    }
};

#endif //MYBOT_SURROUNDED_HPP
