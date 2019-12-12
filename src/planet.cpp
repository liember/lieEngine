#include "includer.hpp"

planet::planet(/* args */) : size(100)
{
    mass = 59722;
    pos = new positionProperty(this);
    connectProperty(pos);
    vel = new speedProperty(this);
    connectProperty(vel);
    tex = new textureProperty(this);
    tex->setTexture("assets/b2.png");
    connectProperty(tex);
    col = new colliderProperty(this);
    col->setDraw(true);
    col->setBody(size, size);
    connectProperty(col);
    gravity = true;
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

void planet::setMass(double val)
{
    mass = val;
}

void planet::setSize(int s)
{
    size = s;
    col->setBody(s, s);
    tex->setTextureSize(s);
}

void planet::collide()
{
    PropertyControlSystem *c = col->findCollision();
    if (c != nullptr)
    {
        std::cout << "lol" << std::endl;
        vel->set(0, 0);
    }
}

bool planet::isGravit()
{
    return gravity;
}