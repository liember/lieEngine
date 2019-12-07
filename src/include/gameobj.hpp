#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "pcs.hpp"
#include "property.hpp"

class gameobj : public PropertyControlSystem
{
private:
    char *tag;

public:
    gameobj(const gameobj &gameobj);

    char *getTag();
    gameobj(const char *name);
    gameobj();
    ~gameobj();
};
