#pragma once

#include "../includer.hpp"

class font
{
private:
  SDL_Color color = {0, 0, 0};
  TTF_Font *f;

public:
  void setColor(int r, int g, int b);

  SDL_Surface *makeText(const char *t);

  font(/* args */);
  font(const char *p);
  ~font();
};
