#include "include/cameraProperty.hpp"
#include <iostream>

camera::camera(PropertyControlSystem *pcs) {
  setID(PROPERTY_CAMERA);
  pos = static_cast<positionProperty *>(pcs->getProperty(PROPERTY_POSITION));
  pos->enableGlobal(false);
  m = static_cast<mouse *>(pcs->getProperty(PROPERTY_MOUSE));
  speed = 0.00001;
  firsttap = true;
}

camera::~camera() {}

void camera::update() {
  if (m->isClicked() && firsttap) {
    firsttap = false;
    sx = m->getx();
    sy = m->gety();
  } else if (m->isClicked()) {
    double dx = m->getx() - sx;
    double dy = m->gety() - sy;

    pos->setGlobal(pos->getGX() - dx * 0.003, pos->getGY() - dy * 0.003);
  } else if (m->isClicked() == false) {
    firsttap = true;
  }
}

void camera::set(double x, double y) { pos->setGlobal(x, y); }

double camera::getX(){
  return pos->getGX();
}

double camera::getY(){
  return pos->getGY();
}