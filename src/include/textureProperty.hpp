#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "pcs.hpp"
#include "property.hpp"
#include "positionProperty.hpp"
#include "texturemanager.hpp"

class textureProperty : public property
{
private:
    int texSize;

    positionProperty *position;
    SDL_Texture *texture;
    SDL_Rect srcR, destR;

public:
    void addTexture(SDL_Texture *t);
    textureProperty(PropertyControlSystem *pcs);
    ~textureProperty();
    void update();
    void draw();

    SDL_Texture *getTexture();

    void setTexture(const char *path);
    void set(SDL_Texture *tex);
    void setTextureSize(int s);
};
