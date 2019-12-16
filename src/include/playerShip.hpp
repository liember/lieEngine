#pragma once

#include "../includer.hpp"

class playerShip : public planet {
private:
  WASDControllerProperty *wasdh; // special for WASD animator
  WASDAnimatorProperty *wasd;

public:
  void setSpeed(double s);

  playerShip(/* args */);
  ~playerShip();
};