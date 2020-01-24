#include "font.hpp"

SDL_Surface *font::makeText(const char *t)
{
  return TTF_RenderText_Solid(f, t, color);
}

void font::setColor(int r, int g, int b)
{
  color.r = r;
  color.g = g;
  color.b = b;
}

font::font(/* args */) { f = TTF_OpenFont("assets/font.ttf", 25); }

font::font(const char *p) { f = TTF_OpenFont(p, 25); }

font::~font() { TTF_CloseFont(f); }
