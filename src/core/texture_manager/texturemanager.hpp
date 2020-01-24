#ifndef _TEXTUE_MANAGER_
#define _TEXTUE_MANAGER_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <fstream>
#include <iostream>

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

#endif