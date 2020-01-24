#include "includer.hpp"

spaceBody::spaceBody(/* args */) : size(100)
{
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

spaceBody::spaceBody(const char *name, int radius, double m, double spX, double spY,
                     double posx, double posy, const char *t)
{
  mass = m;
  pos = new positionProperty(this);
  pos->setX(posx);
  pos->setY(posy);
  connectProperty(pos);
  text = new textProperty(this);
  text->init(name);
  connectProperty(text);
  text->SetSize(60, 20);
  strcpy(title, name);
  vel = new speedProperty(this);
  vel->set(spX, spY);
  connectProperty(vel);
  tex = new textureProperty(this);
  tex->setTextureSize(size * 2);
  tex->setTexture(t);
  connectProperty(tex);
  col = new colliderProperty(this);
  col->setDraw(false);
  size = radius * 2;
  setSize(size);
  col->setBody(size, size);
  connectProperty(col);
  gravity = true;
}

void spaceBody::setTextColor(int r, int g, int b)
{
  text->setColorRGB(r, g, b);
  text->init(title);
}

void spaceBody::setText(const char *t)
{
  text->init(t);
}

spaceBody::~spaceBody()
{
  isLife = false;
}

double spaceBody::getMass() { return mass; }

void spaceBody::setPos(double x, double y)
{
  pos->setX(x);
  pos->setY(y);
}

void spaceBody::setVel(double x, double y) { vel->set(x, y); }

double spaceBody::getPosX()
{
  return pos->getOnlyX() + size / 2;
}

double spaceBody::getPosY()
{
  return pos->getOnlyY() + size / 2;
}

double spaceBody::getGlobX()
{
  return pos->getX();
}

double spaceBody::getGlobY()
{
  return pos->getY();
}

void spaceBody::addVel(double x, double y)
{
  vel->set(vel->getX() + x, vel->getY() + y);
}

void spaceBody::setMass(double val) { mass = val; }

void spaceBody::setSize(int s)
{
  size = s;
  col->setBody(s, s);
  tex->setTextureSize(s);
}

bool spaceBody::collide()
{
  PropertyControlSystem *c = col->findCollision();
  if (c != nullptr)
  {
    return true;
  }
  return false;
}

bool spaceBody::isGravit()
{
  return gravity;
}

void spaceBody::setTex(const char *p)
{
  tex->setTexture(p);
}