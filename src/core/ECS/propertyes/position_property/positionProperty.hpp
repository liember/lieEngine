#pragma once

#include "pcs.hpp"
#include "property.hpp"

class positionProperty : public property
{
private:
  double x;
  double y;

  bool useglobalxy;

  static double gx;
  static double gy;

public:
  void update();
  void draw();

  void setGUsing(bool b);

  void enableGlobal(bool v);

  static void setGlobal(double ix, double iy);
  static void setGlobalX(double x);
  static void setGlobalY(double y);

  static double getGX();
  static double getGY();

  double getX();
  double getY();

  double getOnlyX();
  double getOnlyY();

  void setX(double dx);
  void setY(double dy);

  positionProperty(PropertyControlSystem *pcs);
  ~positionProperty();
};
