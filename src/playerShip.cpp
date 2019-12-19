#include "includer.hpp"

playerShip::playerShip(/* args */)
{
  wasdh = new WASDControllerProperty(this);
  connectProperty(wasdh);
  wasd = new WASDAnimatorProperty(this);
  connectProperty(wasd);
  setText("Player");
  setSize(50);
}

playerShip::playerShip(const char *nickname, int size, double posX, double posY, double spdX,
                       double spdY, const char *imagePath) : spaceBody(nickname, size, 1, spdX, spdY, posX, posY, imagePath)
{
  wasdh = new WASDControllerProperty(this);
  connectProperty(wasdh);
  wasd = new WASDAnimatorProperty(this);
  connectProperty(wasd);
}

playerShip::~playerShip() {}

void playerShip::setSpeed(double s) { wasd->setSpeed(s); }