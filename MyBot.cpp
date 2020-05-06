#include "hlt/game.hpp"
#include "hlt/constants.hpp"
#include "hlt/log.hpp"

#include <random>
#include <ctime>
#include <Blackboard.hpp>
#include <BehaviourTree.hpp>

using namespace std;
using namespace hlt;

int main(int argc, char* argv[]) {
    unsigned int rng_seed;
    if (argc > 1) {
        rng_seed = static_cast<unsigned int>(stoul(argv[1]));
    } else {
        rng_seed = static_cast<unsigned int>(time(nullptr));
    }
    mt19937 rng(rng_seed);

    Game game;

    // At this point "game" variable is populated with initial map data.
    // This is a good place to do computationally expensive start-up pre-processing.
    // As soon as you call "ready" function below, the 2 second per turn timer will start.
    game.ready("MyCppBot");

    log::log("Successfully created bot! My Player ID is " + to_string(game.my_id) + ". Bot rng seed is " + to_string(rng_seed) + ".");

    Blackboard b = Blackboard();
    BehaviourTree btShip = BehaviourTree(&game, &b);
    btShip.addNode(new SequencerFlee(&game, &b, game.me));

    BehaviourTree btShipyard = BehaviourTree(&game, &b);

    for (;;) {
        game.update_frame();
        b.commands.clear();

        shared_ptr<Player> me = game.me;
        unique_ptr<GameMap>& game_map = game.game_map;

        for(auto& ship : me->ships)
        {
            b.ship = ship.second;
            btShip.evaluate();
        }

        btShipyard.evaluate();

        if (!game.end_turn(b.commands)) {
            break;
        }
    }

    return 0;
}
