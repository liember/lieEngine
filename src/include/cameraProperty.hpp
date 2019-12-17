#pragma once

#include "mouse.hpp"
#include "positionLimitProperty.hpp"
#include "property.hpp"

class camera : public property {
private:
  positionLimitProperty *lim;
  positionProperty *pos;
  mouse *m;

  double speed;

  bool firsttap;
  int sx, sy;

public:
  void update();
  void draw() {}

  void set(double x, double y);
  double getX();
  double getY();

  camera(PropertyControlSystem *pcs);
  ~camera();
};
