#pragma once

#include "property.hpp"
#include "pcs.hpp"

#include <SDL2/SDL.h>
#include "game.hpp"

class mouse : public property
{
private:
    int xmp, ymp;

public:
    mouse(PropertyControlSystem *pcs);
    ~mouse();

    int getx();
    int gety();

    void update();
    void draw();
};

mouse::mouse(PropertyControlSystem *pcs)
{
}

mouse::~mouse()
{
}

void mouse::draw()
{
}

void mouse::update()
{
    if (game::event.type == SDL_MOUSEMOTION)
    {
        SDL_GetGlobalMouseState(&xmp, &ymp);
    }
}

int mouse::getx()
{
    return xmp;
}

int mouse::gety()
{
    return ymp;
}