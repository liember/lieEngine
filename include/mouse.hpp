#pragma once

#include "pcs.hpp"

class mouse : public property
{
private:
  int sourceX, sourceY;
  int xmp, ymp;
  //int deltaX, deltaY; is not used

  bool mouseClick;

public:
  mouse(PropertyControlSystem *pcs);
  ~mouse();

  void setCoursor(int x, int y);

  int getx();
  int gety();

  bool isClicked();

  void update();
  void draw() {}
};
