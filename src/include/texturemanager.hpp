#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "pcs.hpp"

class texturemanager
{
private:
    static void checkFile(const char *file_name);

public:
    static SDL_Texture *loadTexture(const char *filename);
    static void draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
    static void draw(SDL_Texture *tex, SDL_Rect dest);
    static void destroyTexture(SDL_Texture *t);
    texturemanager(/* args */);
    ~texturemanager();
};
