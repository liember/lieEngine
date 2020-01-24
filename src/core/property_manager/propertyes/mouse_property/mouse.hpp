#pragma once

#include "../../includer.hpp"

class mouse : public property
{
private:
  int sourceX, sourceY;
  int xmp, ymp;
  int deltaX, deltaY;

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