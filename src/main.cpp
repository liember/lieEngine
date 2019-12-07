#include <iostream>
#include "include/game.hpp"

int main()
{
    game *gae = nullptr;
    gae = new game();
    gae->initEngine("lol", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    gae->initGame();
    try
    {
        while (gae->running())
        {
            gae->handleevents();
            gae->update();
            gae->render();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}