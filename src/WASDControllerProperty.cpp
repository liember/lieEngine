#include "includer.hpp"

WASDControllerProperty::WASDControllerProperty(PropertyControlSystem *pcs)
    : property(PROPERTY_WASD_CONTROLLER)
{
  for (size_t i = 0; i <= 4; i++)
    keyStates[i] = false;
}

WASDControllerProperty::~WASDControllerProperty() {}

bool *WASDControllerProperty::getStates()
{
  return WASDControllerProperty::keyStates;
}

void WASDControllerProperty::update()
{
  if (game::event.type == SDL_KEYDOWN)
  {
    switch (game::event.key.keysym.sym)
    {
    case SDLK_w:
      keyStates[W_KEY] = true;
      break;
    case SDLK_a:
      keyStates[A_KEY] = true;
      break;
    case SDLK_s:
      keyStates[S_KEY] = true;
      break;
    case SDLK_d:
      keyStates[D_KEY] = true;
      break;
    case SDLK_SPACE:
      keyStates[SPACE_KEY] = true;
      break;
    default:
      break;
    }
  }
  if (game::event.type == SDL_KEYUP)
  {
    switch (game::event.key.keysym.sym)
    {
    case SDLK_w:
      keyStates[W_KEY] = false;
      break;
    case SDLK_a:
      keyStates[A_KEY] = false;
      break;
    case SDLK_s:
      keyStates[S_KEY] = false;
      break;
    case SDLK_d:
      keyStates[D_KEY] = false;
      break;
    case SDLK_SPACE:
      keyStates[SPACE_KEY] = false;
      break;
    default:
      break;
    }
  }
}

void WASDControllerProperty::draw() {}