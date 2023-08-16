#include <iostream>

#include "game.hh"
#include "lambdas.hh"
#include "player.hh"

int main()
{
    auto coop = cooperator();
    auto cheat = cheater();
    auto copy = copycat();
    auto detec = detective();
    auto test_game = [](auto strategy1, auto strategy2) {
        Game game(strategy1, strategy2);
        const auto& [score1, score2] = game.play(10);
        std::cout << score1 << " : " << score2 << '\n';
    };

    test_game(coop, cheat);
    test_game(coop, copy);
    test_game(cheat, copy);

    test_game(cheat, detec);
    test_game(coop, detec);
}
