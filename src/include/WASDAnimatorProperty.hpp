#pragma once

#include "WASDControllerProperty.hpp"
#include "pcs.hpp"
#include "positionLimitProperty.hpp"
#include "property.hpp"
#include "speedProperty.hpp"

#include <SDL2/SDL.h>

class WASDAnimatorProperty : public property {
private:
  positionLimitProperty *lim;
  speedProperty *vel;
  WASDControllerProperty *controller;
  positionProperty *pos;
  double speed;
  bool inertion;

  void moveVertical(double val);
  void moveHorizontal(double val);

public:
  void setInertion(bool val);
  void setSpeed(double speed);

  void update();
  void draw() {}

  WASDAnimatorProperty(PropertyControlSystem *pcs);
  ~WASDAnimatorProperty();
};
