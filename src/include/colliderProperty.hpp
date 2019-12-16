#pragma once

#include "SDL2/SDL.h"
#include "game.hpp"
#include "pcs.hpp"
#include "positionProperty.hpp"
#include "property.hpp"

#include <algorithm>
#include <vector>

class colliderProperty : public property {
private:
  static std::vector<colliderProperty *> colliders;

  SDL_Rect body;
  bool drawBody;
  positionProperty *pos;

  PropertyControlSystem *p;

public:
  void setDraw(bool b);
  bool detect(SDL_Rect b);

  void draw();
  void update();

  PropertyControlSystem *getPcs();

  PropertyControlSystem *findCollision();

  colliderProperty(PropertyControlSystem *pcs);
  ~colliderProperty();

  SDL_Rect getBody();
  void setBody(int w, int h);
};