#pragma once

#include "../includer.hpp"
#include "mouse.hpp"

class buttonProperty : public property {
private:
  positionProperty *pos;
  SDL_Rect but;
  mouse *m;
  textProperty *text;

  int paddingX = 10;
  int paddingY = 60;

  double time;
  double delay;

  bool fill;

public:
  buttonProperty(PropertyControlSystem *pcs);
  ~buttonProperty();

  bool isPressed();

  void setSize(int w, int h);
  void setPos(double x, double y);

  void press();
  void draw();
  void update();
};
