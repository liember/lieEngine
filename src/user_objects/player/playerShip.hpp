#pragma once

#include "../includer.hpp"

class playerShip : public spaceBody
{
private:
  WASDControllerProperty *wasdh; // special for WASD animator
  WASDAnimatorProperty *wasd;

public:
  void setSpeed(double s);

  playerShip(/* args */);
  playerShip(const char *nickname, int size, double posX, double posY, double spdX, double spdY, const char *imagePath);
  ~playerShip();
};