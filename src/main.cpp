#include "core.hpp"
#include <iostream>

int main()
{
    core game;
    game.Init();
    while (game.IsRunning())
    {
        game.Update();
    }
}