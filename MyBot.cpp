#include "hlt/game.hpp"

#include <random>
#include <ctime>
#include "hlt/SequencerCollectHalite.hpp"
#include "hlt/CheckHalite.hpp"
#include "hlt/CheckRemaningShips.hpp"
#include "hlt/CheckForRemainingTurns.hpp"
#include "hlt/CreateShip.hpp"
#include "hlt/Blackboard.hpp"
#include "hlt/BehaviourTree.hpp"
#include "hlt/CheckShipCapacity.hpp"
#include "hlt/MoveTowards.hpp"
#include "hlt/FindHalite.hpp"
#include "hlt/SequencerTransform.hpp"
#include "hlt/SequencerDropHalite.hpp"
#include "hlt/SequencerAttack.hpp"
#include "hlt/SequencerSpawnShip.hpp"
#include "hlt/SequencerWait.hpp"
#include "hlt/constants.hpp"

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

    shared_ptr<Player> me = game.me;

    Blackboard b = Blackboard();
    b.m_player = me;
    b.m_game = &game;

    BehaviourTree btShip = BehaviourTree(&b);
    btShip.addNode(new SequencerFlee(&b));
    btShip.addNode(new SequencerCollectHalite(&b));
    btShip.addNode(new SequencerTransform(&b));
    btShip.addNode(new SequencerDropHalite(&b));
    btShip.addNode(new SequencerAttack(&b));
    btShip.addNode(new SequencerWait(&b));

    BehaviourTree btShipyard = BehaviourTree(&b);

    btShipyard.addNode(new SequencerSpawnShip(&b));

    for (;;) {
        game.update_frame();
        b.m_commands.clear();

        btShipyard.evaluate();

        for(auto& ship : me->ships)
        {
            b.m_ship = ship.second;
            btShip.evaluate();
        }

        if (!game.end_turn((b.m_commands))) {
            break;
        }
    }

    return 0;
}
