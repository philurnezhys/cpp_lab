#include <memory>

#include "game/game.h"
#include "strategies/human.h"
#include "strategies/computer1.h"
#include "strategies/computer2.h"


int main() {
//    auto player1 = std::make_shared<computer_strategy_t_1>("First player");
    auto player2 = std::make_shared<computer_strategy_t_2>("Second player");

    auto player1 = std::make_shared<human_strategy_t>("First player");
//    auto player2 = std::make_shared<human_strategy_t>("Second player");

    game_t game(player1, player2);
    game.play();

    return 0;
}
