#include "hlt/game.hpp"

#include <random>
#include <ctime>
#include "hlt/CheckHalite.hpp"
#include "hlt/CheckRemaningShips.hpp"
#include "hlt/CheckForRemainingTurns.hpp"
#include "hlt/CreateShip.hpp"
#include "hlt/Blackboard.hpp"
#include "hlt/BehaviourTree.hpp"
#include "hlt/CheckShipCapacity.hpp"
#include "hlt/MoveTowards.hpp"
#include "hlt/FindHalite.hpp"
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
    btShip.addNode(new SequencerFlee(&game, &b, game.me));

    Sequencer* s = new Sequencer(&b);
    s->addNode(new CheckShipCapacity(&b, constants::MAX_HALITE, LESS));
    s->addNode(new FindHalite(&b));
    s->addNode(new MoveTowards(&b));

    btShip.addNode(s);

    BehaviourTree btShipyard = BehaviourTree(&b);

    Sequencer* s1 = new Sequencer(&b);

    s1->addNode(new CheckHalite(&b, 1000, GREATER));
    s1->addNode(new CheckRemainingShips(&b, 8, LESS));
    s1->addNode(new CheckForRemainingTurns(&b, 10, GREATER));
    s1->addNode(new CreateShip(&b));

    btShipyard.addNode(s1);

    for (;;) {
        game.update_frame();
        b.m_commands.clear();

        btShipyard.evaluate();

        for(auto& ship : me->ships)
        {
            b.m_ship = ship.second;
            btShip.evaluate();
        }

        log::log(to_string(b.m_commands.size()));

        if (!game.end_turn((b.m_commands))) {
            break;
        }
    }

    return 0;
}
