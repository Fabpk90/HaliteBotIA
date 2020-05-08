//
// Created by fab on 08/05/2020.
//

#ifndef MYBOT_CHECKFOREMPTYCELL_HPP
#define MYBOT_CHECKFOREMPTYCELL_HPP

#include "Node.hpp"

class CheckForEmptyCell : public Node
{
public:

    CheckForEmptyCell(Blackboard* b) : Node(b){};

    bool evaluate() override
    {
        hlt::log::log("check empty cell");
        //TODO: this is not really modular
        return !m_blackboard->m_game->game_map->at(m_blackboard->m_player->shipyard->position)->is_occupied();
    }
};
#endif //MYBOT_CHECKFOREMPTYCELL_HPP
