#include "mouse.hpp"

mouse::mouse(PropertyControlSystem *pcs)
{
  mouseClick = false;
  setCoursor(0, 0);
  SDL_GetMouseState(&sourceX, &sourceY);
}

mouse::~mouse() {}

void mouse::update()
{
  if (game::event.type == SDL_MOUSEMOTION)
  {
    SDL_GetMouseState(&xmp, &ymp);
  }
  if (game::event.type == SDL_MOUSEBUTTONDOWN)
  {
    mouseClick = true;
  }
  if (game::event.type == SDL_MOUSEBUTTONUP)
  {
    mouseClick = false;
  }
}

void mouse::setCoursor(int x, int y)
{
  SDL_WarpMouseInWindow(game::getWindow(), x, y);
}

int mouse::getx() { return xmp; }

int mouse::gety() { return ymp; }

bool mouse::isClicked() { return mouseClick; }