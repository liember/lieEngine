#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "property.hpp"
#include "positionProperty.hpp"
#include "pcs.hpp"

class tilemap : public property
{
private:
    positionProperty *pos;

    SDL_Rect src, dest;

    SDL_Texture *dirt;
    SDL_Texture *grass;
    SDL_Texture *water;

    int x;
    int y;

    int map[10][10];
    int tile_size = 10;

public:
    void setTileSize(int s);
    void loadMap(int arr[10][10]);

    void draw();
    void update();

    void setPos(int xp, int yp);

    tilemap(PropertyControlSystem *pcs);
    ~tilemap();
};
