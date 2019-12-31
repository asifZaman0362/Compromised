#include "Game.hpp"

int main()
{
    using namespace TstBits;
    
    Settings settings;
    Game game(settings);
    game.Start();

    return EXIT_SUCCESS;
}