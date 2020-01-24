#pragma once

#include "../../includer.hpp"
#include "font/font.hpp"

class textProperty : protected font, public property
{
private:
  SDL_Texture *texture;
  positionProperty *pos;

  void getTextureText(const char *t);
  void correctTexture();

  SDL_Rect dstrect;

public:
  void update();
  void draw();

  void setColorRGB(int r, int g, int b);
  void SetSize(int w, int h);
  void init(const char *t);

  textProperty(PropertyControlSystem *pcs);
  ~textProperty();
};
