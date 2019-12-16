#include "includer.hpp"

playerShip::playerShip(/* args */) {
  wasdh = new WASDControllerProperty(this);
  connectProperty(wasdh);
  wasd = new WASDAnimatorProperty(this);
  connectProperty(wasd);
  setText("Player");
  setSize(50);
}

playerShip::~playerShip() {}

void playerShip::setSpeed(double s) { wasd->setSpeed(s); }