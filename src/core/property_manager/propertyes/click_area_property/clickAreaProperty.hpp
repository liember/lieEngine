#pragma once

#include "../../includer.hpp"

class clickAreaProperty : public property
{
private:
  positionProperty *pos;
  SDL_Rect but;
  mouse *m;
  textProperty *text;

  int paddingX;
  int paddingY;

  SDL_Color HoverColor;
  SDL_Color ClickColor;

  bool bg = false;
  SDL_Color NormalColor;

  SDL_Color BorderColor;

  double time;
  double delay;

  bool click;
  bool hover;

  bool GPosUse;

public:
  clickAreaProperty(PropertyControlSystem *pcs);
  ~clickAreaProperty();

  void setDelay(double d);

  bool isPressed();
  bool isHovered();

  void setGPosUsing(bool v);

  void setSize(int w, int h);
  void setPos(double x, double y);

  void press();
  void draw();
  void update();

  void setPaddingX(int v);
  void setPaddingY(int v);

  void setHoverColor(int r, int g, int b, int a = 255);
  void setClickColor(int r, int g, int b, int a = 255);

  void setNormalColor(int r, int g, int b, int a = 255);

  void setBorderColor(int r, int g, int b, int a = 255);
};
