#include "include/game.hpp"
#include <iostream>

int main() {
  game *gae = nullptr;
  gae = new game();
  gae->initEngine("lie and ember", SDL_WINDOWPOS_CENTERED,
                  SDL_WINDOWPOS_CENTERED, 1200, 600, false);
  try {
    while (gae->running()) {
      gae->handleevents();
      gae->update();
      gae->render();
    }
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
  }
}