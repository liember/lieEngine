#pragma once

#include "../../includer.hpp"

class speedProperty : public property
{
private:
  double x, y;
  positionProperty *position;

public:
  speedProperty(PropertyControlSystem *pcs);
  ~speedProperty();

  void set(double dx, double dy);

  double getX();
  double getY();

  void update();
  void draw();
};