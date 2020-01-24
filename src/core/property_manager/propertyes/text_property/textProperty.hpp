#ifndef _TEXT_PROPERTY_
#define _TEXT_PROPERTY_

#include "font/font.hpp"
#include "../position_property/positionProperty.hpp"
#include "../../pcs.hpp"

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

#endif