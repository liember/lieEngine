#include "core.hpp"
#include <iostream>

int main()
{
  Core::Game gae;
  gae.initEngine("lie and ember", SDL_WINDOWPOS_CENTERED,
                 SDL_WINDOWPOS_CENTERED, 1200, 600, false);
  while (gae.running())
  {
    gae.handleevents();
    gae.update();
    gae.render();
  }
}