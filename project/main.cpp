#include "core.hpp"
#include <iostream>

int main()
{
  Core::MinimalCore gae;
  gae.initEngine("LieEngine v2.3", SDL_WINDOWPOS_CENTERED,
                 SDL_WINDOWPOS_CENTERED, 1200, 600, false);
  while (gae.running())
  {
    gae.handleevents();
    gae.update();
    gae.render();
  }
}