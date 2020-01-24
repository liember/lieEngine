#ifndef _TEXTURE_PROPERTY_
#define _TEXTURE_PROPERTY_

#include "../../pcs.hpp"
#include "../position_property/positionProperty.hpp"

class textureProperty : public property
{
private:
  int texSize;

  positionProperty *position;
  SDL_Texture *texture;
  SDL_Rect destR;

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

#endif