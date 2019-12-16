#include "includer.hpp"

planet::planet(/* args */) : size(100) {
  mass = 59722;
  pos = new positionProperty(this);
  connectProperty(pos);
  vel = new speedProperty(this);
  connectProperty(vel);
  text = new textProperty(this);
  connectProperty(text);
  text->init("undefined");
  text->SetSize(60, 20);
  tex = new textureProperty(this);
  tex->setTexture("assets/b2.png");
  connectProperty(tex);
  col = new colliderProperty(this);
  col->setDraw(true);
  col->setBody(size, size);
  connectProperty(col);
  gravity = true;
}

planet::planet(const char *name, int radius, double m, double spX, double spY,
               double posx, double posy, const char *t) {
  mass = m;
  pos = new positionProperty(this);
  pos->setX(posx);
  pos->setY(posy);
  connectProperty(pos);
  text = new textProperty(this);
  text->init(name);
  connectProperty(text);
  text->SetSize(60, 20);
  vel = new speedProperty(this);
  vel->set(spX, spY);
  connectProperty(vel);
  tex = new textureProperty(this);
  tex->setTextureSize(size * 2);
  tex->setTexture(t);
  connectProperty(tex);
  col = new colliderProperty(this);
  col->setDraw(true);
  size = radius * 2;
  setSize(size);
  col->setBody(size, size);
  connectProperty(col);
  gravity = true;
}

void planet::setText(const char *t) { text->init(t); }

planet::~planet() {}

double planet::getMass() { return mass; }

void planet::setPos(double x, double y) {
  pos->setX(x);
  pos->setY(y);
}

void planet::setVel(double x, double y) { vel->set(x, y); }

double planet::getPosX() { return pos->getOnlyX() + size / 2; }

double planet::getPosY() { return pos->getOnlyY() + size / 2; }

double planet::getGlobX() { return pos->getX(); }

double planet::getGlobY() { return pos->getY(); }

void planet::addVel(double x, double y) {
  vel->set(vel->getX() + x, vel->getY() + y);
}

void planet::setMass(double val) { mass = val; }

void planet::setSize(int s) {
  size = s;
  col->setBody(s, s);
  tex->setTextureSize(s);
}

void planet::collide() {
  PropertyControlSystem *c = col->findCollision();
  if (c != nullptr) {

    vel->set(0, 0);
  }
}

bool planet::isGravit() { return gravity; }

void planet::setTex(const char *p) { tex->setTexture(p); }