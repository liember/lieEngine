#include "includer.hpp"

planet::planet(/* args */)
{
    mass = 59722;
    pos = new positionProperty(this);
    connectProperty(pos);
    vel = new speedProperty(this);
    connectProperty(vel);
    tex = new textureProperty(this);
    tex->setTexture("assets/b2.png");
    connectProperty(tex);
}

planet::~planet()
{
}

double planet::getMass()
{
    return mass;
}

void planet::setPos(double x, double y)
{
    pos->setX(x);
    pos->setY(y);
}

void planet::setVel(double x, double y)
{
    vel->set(x, y);
}

double planet::getPosX()
{
    return pos->getOnlyX();
}

double planet::getPosY()
{
    return pos->getOnlyY();
}

void planet::addVel(double x, double y)
{
    vel->set(vel->getX() + x, vel->getY() + y);
}