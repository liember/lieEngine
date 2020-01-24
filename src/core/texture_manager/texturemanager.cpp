#include "include/texturemanager.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "include/exeptions.hpp"
#include "include/game.hpp"
#include "include/pcs.hpp"

#include <fstream>
#include <iostream>

using namespace std;

texturemanager::texturemanager(/* args */) {}

texturemanager::~texturemanager() {}

void texturemanager::checkFile(const char *file_name)
{
  ifstream file;
  file.open(file_name);
  if (!file)
    throw new fileNotExist();
}

SDL_Texture *texturemanager::loadTexture(const char *filename)
{
  checkFile(filename);
  cout << "[?] Load texture" << filename << endl;
  SDL_Surface *tempSurf = IMG_Load(filename);
  SDL_Texture *tex =
      SDL_CreateTextureFromSurface(game::getRenderer(), tempSurf);
  SDL_FreeSurface(tempSurf);

  return tex;
}

void texturemanager::draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest)
{
  SDL_RenderCopy(game::getRenderer(), tex, &src, &dest);
}

void texturemanager::draw(SDL_Texture *tex, SDL_Rect dest)
{
  SDL_RenderCopy(game::getRenderer(), tex, nullptr, &dest);
}

void texturemanager::destroyTexture(SDL_Texture *t) { SDL_DestroyTexture(t); }